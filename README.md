# Cplusplus-Program

## Corner Grocer Chada Tech

This is an item-tracking program for the Corner Grocer store. The program analyzes the text records that Chada Tech has generated for their produce section throughout the day. It displays how often produce items are purchased from the Corner Grocer. The user has a menu choice of three different ways to see the data: 1) by inputting a produce item and receiving the numeric amount it was purchased, 2) displaying a list of all items and the purchase frequencies, or, 3) viewing the same list, but in a histogram format).

I created a StoreMenu Class that handles all the menu options for the user, ensuring that the user has options and can get easily get the information they want. I also implemented user input validation and handled errors that may occur.

My code could be enhanced by accepting the plural OR non-plural form of a produce item. As of right now, the program only recognizes the produce items in plural form (so inputting "apple" would return 0 even if there were multiple apples purchased). This improvement would make the program more user-friendly.

The most challenging part of this project for me was reading the purchased items from a txt file, and writing/organizing them into a separate (dat) file, and a Map. I used Zybooks and other online resources like Stack Overflow to learn about Maps and how to iterate through them in C++.

I believe that creating a Class with data members and member functions is a skill from this project that will continue to be useful during future projects. Object-oriented programming is built upon classes and objects, so understanding how to build and use them opens a lot of doors to what a developer can create. I made this code maintainable, readable, and adaptable by adding clear comments that describe the each part of the code. This makes it easier for myself and others to understand the code and to add to it.
