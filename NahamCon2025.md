## NahamCon 2025 Writeup

### Challenge Name: `Read The Rules`

This was quite a simple one, possibly to force us to read the rules of the CTF. The description was as follows:
![Image](NahamCon2025/readRules.png)

Clicking on the link led to the [rules](https://ctf.nahamcon.com/rules) page, which had this with no visuble flag (or so you would think at a first glance):
![Image](NahamCon2025/Rules.png)


However, when you open the developer tools and inspect the page, you come across the flag, hidden as a comment between the "Flag Format" and "Support" sections:


![Image](NahamCon2025/hiddenRuleFlag.png)

```</p>
<!-- Main CTF - Read The Rules: flag{90bc54705794a62015369fd8e86e557b} -->
<h5 class="mb-2">Support</h5>
```


### Flag: `flag{90bc54705794a62015369fd8e86e557b}`