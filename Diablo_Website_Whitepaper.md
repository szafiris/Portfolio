# Diablo 3 Website Whitepaper

## Application Description
The use of this application is to be able to see the current status of your hero in Diablo 3 and see what types of equipment the hero has equipped, the level of their artisans, and the special items each follower has. They can see the equipment the character has, as well as their followers, artisans and skills. When the user opens the site, they will see their hero profile which will contain their hero's name and the equipment the hero currently has on them. They can then click to either the followers tab or the skills tab. If they click on the follower’s tab, they will see a list of their followers along with the artisans that are linked to the hero. If they click on the skills tab, they will see the skills that are currently associated with that hero.

### Web Service(s) Used
I will be using the Diablo 3 API made by Blizzard. I will be using the get hero call, get follower Equipment call, and the get hero equipment call. The get account heroes call will pull all the heroes from a specific account and load the data onto the page. The get follower equipment call will get the followers special items for a particular hero. The get equipment call will retrieve a list of each item the hero currently has in their inventory and on their person.  All of the information on each of the different API calls can be found at https://dev.battle.net/io-docs.

## Top-Level Design/Layout
![diablo3_home](https://github.com/szafiris/Portfolio/blob/master/diablo3_home.PNG)
![hero_list](https://github.com/szafiris/Portfolio/blob/master/hero_list.PNG)
![hero_info](https://github.com/szafiris/Portfolio/blob/master/hero_info.PNG)

## Usage Scenarios

### Viewing Heroes
The user wants to know about the heroes their account has. The user clicks onto the site and then enters their battle tag into the search bar and clicks search.
![diablo3_home](https://github.com/szafiris/Portfolio/blob/master/diablo3_home.PNG)
![hero_list](https://github.com/szafiris/Portfolio/blob/master/hero_list.PNG)

### Viewing Equipment
Our user is curious about the equipment a specific hero has. The user clicks onto the site and then enters their battle tag into the search bar. They then select their hero from the results list and the equipment list will display with the hero's profile.
![diablo3_home](https://github.com/szafiris/Portfolio/blob/master/diablo3_home.PNG)
![hero_list](https://github.com/szafiris/Portfolio/blob/master/hero_list.PNG)
![hero_info](https://github.com/szafiris/Portfolio/blob/master/hero_info.PNG)

## Design Rationale
I decided to go with a dark color palette for the site for a number of reasons. The most prominent one being that the game diablo has a very dark color palette, with blues and grays being prominent colors on the site. I wanted to keep the same color palette so the user will make a connection between my Diablo 3 site and the actual game. Another reason I had for using dark UI is that a darker screen is easier on the eyes, especially if it is being used in darker lighting. Since my website is gaming related, I figured it would be used in more gaming-based settings. UX Collective states that the “reason behind the dark theme on entertainment platforms, such as Steam, Spotify, YouTube and Netflix, is that users tend to engage in such activities later in the day, after work or in a room with dimmed lights”. Since gaming is mostly done in darker lighting, a dark UI would be better suited for the user. I also tried to keep my site very simplistic as it will be much easier for the user to navigate and use the site if there are less things on the page. Usability.gov states that “best interfaces are almost invisible to the user. They avoid unnecessary elements and are clear in the language they use on labels and in messaging”. The less the user can interact with, the better the site. That way the user does not get lost in useless actions and they feel like they can easily learn the site. That is why my site only has a few buttons the user can interact with. I chose the font Palatino Linotype because it is a very readable font, but it is less formal than a font like Times New Roman. I wanted the font of the site to be easy to read, but to not give off an academic tone as this is a site about a videogame.

## Usability Metric Forecast
I focused on learnability as my site design centers around reading from left to right since the API I am pulling from is made for US users. This means that all of my users will be accustomed to looking from left to right, so the site reflects that. My site also is on one page, so the user cannot get lost in multiple pages and pop ups. All of the information is organized on the page and you do not need to click in further to find all of your information. This will help make the site easy to navigate. Everything is also labeled in order to help the user understand what everything is. One problem with it is that the information on the page can seem overwhelming. Because all of the hero information is on one page, the user can get overwhelmed by all the information if they are only looking for one piece of the information. I focused on efficiency by keeping all the information on the site within one click. This way the user can easily get to any part of the site without having to go through multiple jumps. Minimizing the clicks that the user can do also helps to reduce my rate of errors by the user. By limiting the interaction between the user and the site, I reduce that rate in which they can make mistakes. The only real mistake that user can make putting in the wrong account name or clicking on the wrong hero, which are relatively easy mistake to recover from. The emphasis on memorability comes from the fact that the site is very simplistic, so there is not a lot that the user has to remember. I try to only show the user the most necessary information in order to make it very easy for them to retain the information that is present to them. I picked a simplistic font as well so it is easy for the user to read the text on the screen, which helps towards both memorability and efficiency. My site has a very minimalistic design which was made with subjective satisfaction in mind. Because everything is clean and simple, in general, most people will find it appealing. While some may think the site is too bland, they will not be completely turned off by it as opposed to a site that feels too overwhelming in design.

## References
“API Docs.” Blizzard, Blizzard, dev.battle.net/io-docs.

Maltezou, Constantina. “Dark or Light UI? The UX Influence. – UX Collective.” UX Collective, UX Collective, 26 July 2017, uxdesign.cc/dark-or-light-ui-the-ux-influence-ca6df6aff390.

“User Interface Design Basics.” Usability.gov, Department of Health and Human Services, 21 May 2014, www.usability.gov/what-and-why/user-interface-design.html.
