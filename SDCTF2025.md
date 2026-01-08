## SDCTF2025 Writeup

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="NahamCon2025.html">NahamCon 2025</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a>
</div>
<div style="flex:1;text-align:right">
<a href="SDCTF2023.html">SDCTF 2023</a></div>
</div>

## Challenge Directory

[Piotr's Day Off: Day 2](#challenge-name-piotrs-day-off-day-2)

[Piotr's Day Off: Day 4](#challenge-name-piotrs-day-off-day-4)

[Piotr's Day Off: Day 5](#challenge-name-piotrs-day-off-day-5)


### Challenge Name: `Piotr's Day Off: Day 2`

To get context for this challenge, you would have to read the description of the previous day, and here it is:
![Image](SDCTF2025/piotrDay1.png)

So... We know that Piotr was last seen at the Sun God Festival in San Diego. The sun god festival happened on Saturday, May 3rd, and I already knew this as I was physically there, but I assume that you can probably find this information online.

I didn't know that I was solving for Day 2 initially, but since this is a writeup for that day, here's the description for Day 2:
![Image](SDCTF2025/piotrDay2.png)


Ahh yes, the infamous no more info challenge description. Anyway, at first I didn't really know where to start, and the only lead that I did have was that Piotr was last seen at the Sun God Festival, and that he is a board member of ACM @ UCSD. I decided to really look into that first bit of information.

I went onto google and searched for ```wooli piotr```, and I found something quite interesting:
![Image](SDCTF2025/wooliPiotr.png)

The first instagram link led to this, which was a post made by Piotr:
![Image](SDCTF2025/instaSideProfile.png)

This was posted on May 5th, 2025, which was when I realized that this might be the flag to challenge corresponding to Day 2.

I then decided to reverse image search this photo, and I found that it was actually a photo of Piotr at the Kitty Hawk Pier in North Carolina:
![Image](SDCTF2025/kittyHawkPier.png)

So I tried submitting that and thus here's the flag for Day 2:

### Flag: ```Kitty Hawk```

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="NahamCon2025.html">NahamCon 2025</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a> /
<a href="SDCTF2025.html#">Top</a>
</div>
<div style="flex:1;text-align:right">
<a href="SDCTF2023.html">SDCTF 2023</a></div>
</div>

<br/><br/>
<br/><br/>


### Challenge Name: `Piotr's Day Off: Day 4`

Here's the description for Day 4:
![Image](SDCTF2025/piotrDay4.png)

I decided to go to the ACM @ UCSD website to see if there was any information about Piotr, and I found this:
![Image](SDCTF2025/acmPiotr.png)

Then I searched up his name on google, and these were the results:
![Image](SDCTF2025/nameSearch.png)

Went onto LinkedIn and found this:
![Image](SDCTF2025/linkedin.png)

I then clicked on the link he had there, which led to this:
![Image](SDCTF2025/sultangamer06.png)

I tried reverse image searching this, but it always led be back to somewhere in San Diego, Sunset Cliffs.

I then tried clicking on the link at the bottom to go to his GitHub:
![Image](SDCTF2025/bottomLink.png)

Here's his GitHub:
![Image](SDCTF2025/github.png)

I then explored the repository he had on there, looking through the commits to see if there was anything interesting, and I found this:
![Image](SDCTF2025/zeets.png)

```Check out my Xeets on X.```

hmm... how suspicious. I then went looking through his deployments, and I found a very interesting red "X":

![Image](SDCTF2025/redX.png)

wow we just got his username for X just like that!
![Image](SDCTF2025/unameX.png)

Here were some of his tweets, but that link at the top seems to be quite interesting:
![Image](SDCTF2025/xTweets.png)

Clicking on that leads to this, and that gas station is definitely not in Texas:
![Image](SDCTF2025/tSocialTexas.png)

I had to search for a little bit, but I eventually found a reference to Tunisia and their gas station stock pics:
![Image](SDCTF2025/ShellRevImage.png)


Finally, I serarched up a list of Tunisian cities, and the flag ended up being the first result:
![Image](SDCTF2025/tunisianCities.png)

### Flag: ```Tunis```

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="NahamCon2025.html">NahamCon 2025</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a> /
<a href="SDCTF2025.html#">Top</a>
</div>
<div style="flex:1;text-align:right">
<a href="SDCTF2023.html">SDCTF 2023</a></div>
</div>

<br/><br/>
<br/><br/>

### Challenge Name: `Piotr's Day Off: Day 5`

Here's the description for Day 5:
![Image](SDCTF2025/piotrDay5.png)

This challenge continued on from the previous day, and here's the clue, another truth social post by Piotr:
![Image](SDCTF2025/changeHeart.png)

I went onto bluesky and searched up Piotr's Truth Social username, and thanks to the auto suggestions, I was able to find his account:
![Image](SDCTF2025/suggestions.png)

I found a series of Bluesky posts, or whatever you call them, and here they are:
![Image](SDCTF2025/bSkyPosts.png)

From here, I was able to deduce that "magic die zusammenkunft" is Magic the Gathering in German, from which I now know Piotr may be in Germany.

I then scoured google for Magic the Gathering events in Germany, and I didn't really find anything. I also searched for Smash Brothers events in Germany, but no dice here either.
![Image](SDCTF2025/failSmashBros.png)



I then decided to search for smash brothers events in general, and what is that first link that I see?? A REDDIT POST????:

![Image](SDCTF2025/smashEvents.png)


Next, I decided to ```CTRL + F``` the page for "Germany" and I found this to be quite interesting:
![Image](SDCTF2025/ctrlF.png)


I tried submitting that as the city, and there it was! It perfectly matched the dates that Piotr was there, and thus the flag was found:

### Flag: ```Großlohra```

It was interesting that this flag had a special character in it, and I was not expecting that at all. I thought it was going to be a simple city name, but I guess not! 😅

I wasn't really able to find the other flags in time, but honestly I was just using my phone to search for all of this, I assume it would have been a lot easier if I had used my computer instead hahaha. It was still quite a fun series of challenges, and I really enjoyed the process of solving them. I hope you enjoyed reading this writeup as much as I enjoyed writing it! 😁

<div style="display:flex;align-items:center;width:100%">
<div style="flex:1;text-align:left">
<a href="NahamCon2025.html">NahamCon 2025</a>
</div>
<div style="flex:1;text-align:center">
<a href="index.html">Home</a> /
<a href="SDCTF2025.html#">Top</a>
</div>
<div style="flex:1;text-align:right">
<a href="SDCTF2023.html">SDCTF 2023</a></div>
</div>