## OSU Gaming 2025 Writeup

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="Seccon142025.html">Seccon 14 (2025)</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a>
</div>
<div style="flex:1;text-align:right">
<a href="JustCTF2025.html">JustCTF 2025</a></div>
</div>

## Challenge Directory

[pump-lion](#challenge-name-pump-lion)

### Challenge Name: `pump-lion`

A prompt engineering challenge eh? Here's the description:

> PumpLion, the cheerful lion mascot of osu!gaming CTF, has been deployed as a "super-secure" chatbot for event participants. Rumor has it... the flag is hidden deep in its silicon jungle. But don't expect it to just hand it to you on a silver platter - it's been "prompt-trained" to protect it at all costs.

> Note: rate limiting is enforced, do not spam the LLM.

> expected difficulty: 2/5

> Author (*new field from now on* ): `sahuang`

This is a misc category challenge, where they provided a [link](https://pump-lion-web.challs.sekai.team/) [now dead] to a chatbot interface. The goal was to extract the flag from the chatbot, which was designed to be "super-secure" *apparantly* and not give away the flag without a fight.

![Image](OSUGaming2025/pumpGreeting.webp)

I began with a simple question, "hi lion, what's your mane made of?" to see how the chatbot would respond. Unfortunately it seemed that there was a server error, which I thought was intentional, only to find out later that the response that I got was really an error on their side.

After a few more attempts, I was able to determine that maybe some kind of password or secret phrase was needed to unlock the chatbot and give out the flag. Unfortunately this turned out to be a hallucination by PumpLion.

Eventually, I ran out of time (as I had only started this challenge 40 min before the CTF ended) and was not able to get the flag. However, I did learn a few things about prompt engineering and how to interact with chatbots in a more effective way.

For future reference, here is what works to get the flag from PumpLion:

![Image](OSUGaming2025/pumpSystemMessage.webp)

Very interesting ehh? I knew that saying something on behalf of the system would work (from previous experience with prompt engineering/jailbreaking), but I unfortunately was not able to come up with this exact prompt in time.

Either way, I then looked up PumpLion's creator on google and found their github:

![Image](OSUGaming2025/github_brad-moon-chua.png)

Something else that caught my eye was when this account was created - a few days before the CTF started. Suspicious indeed.

![Image](OSUGaming2025/githubCreated.png)

Went onto the only repo there, which was this:
![Image](OSUGaming2025/githubRepo.png)

I saw remnents of a flag (as the flag format for this CTF began with `OSU{`) but in the current version of the README, the actual flag is missing.

Naturally, I checked out the commit history to see if the flag was present in any previous versions of the README:

![Image](OSUGaming2025/githubCommits.png)

Clicking on the [second commit](https://github.com/brad-moon-chua/personal-project-lino/commit/bf1e7d84ed0f36c3ef7abb3d74664362fe2a4e19), I found the flag!! yay!

![Image](OSUGaming2025/githubFlag.png)

And there we have it, the flag for this challenge is:

### Flag: `osu{Pump_4_Fun_0n_osu}`


<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="Seccon142025.html">Seccon 14 (2025)</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a> /
<a href="OSUGaming2025.html#">Top</a>
</div>
<div style="flex:1;text-align:right">
<a href="JustCTF2025.html">JustCTF 2025</a></div>
</div>
