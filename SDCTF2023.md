## SDCTF2023 Writeup

### Challenge Name: `Fork bomb protector`

Here is the challenge on the website 🕷🕸:
![Image](SDCTF2023/challengeScrn.jpg)

After reading the description, and as I did hear about fork bombs from a youtube video before, I sort of knew what they were aiming to do here.

Anyway, I then decided to check out what was in nofork.py 🙈🍴:
```
#! /usr/bin/env python3
import os
from seccomp import SyscallFilter, ALLOW, ERRNO
from errno import EPERM

FORBID = ERRNO(EPERM)

# Ban all fork-related syscalls to prevent fork bombs
def init_seccomp():
    f = SyscallFilter(defaction=ALLOW)

    f.add_rule(FORBID, "fork")
    f.add_rule(FORBID, "vfork")
    f.add_rule(FORBID, "clone")

    f.load()

init_seccomp()
os.execvp('bash', ['bash'])
```
I found that forking or cloning was not allowed. In hindsight, I wish I had researched what this was, and not just moved on to the next thing 😅

Anyway, using the terminal, I was able to log onto the remote machiene to begin the challenge 📺🖱
![Image](SDCTF2023/logOn.jpg)



https://stackoverflow.com/questions/22377792/how-to-use-echo-command-to-print-out-content-of-a-text-file

https://www.baeldung.com/linux/read-command