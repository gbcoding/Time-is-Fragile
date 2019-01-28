Demo version of Time is Fragile

Time is Fragile is a text based game that allows players to explore their environment, take on quests,
interact with characters, and find items along the way. This is a demo version of the first level of 
the game, the Laboratory.

Written Fall 2016 for CSCE 1040, Beginning Computer Science II

Story and Dialogue written by Garrett Brumley.

C++ code written by Garrett Brumley with contributions from Jacob Montes.

Built using Visual Studio 2015/2017 using
  - Windows API <Windows.h>
  - Standard C/C++ libraries including
    - iostream
    - iomanip
    - fstream
    - string
    - cstring
    - cctype
    - stdio.h
    - stdlib.h


Files included:

  - main.cpp - Main function that runs the story and calls external classes
  
  - Avatar.h and Avatar.cpp - Class that represents the player in game. An avatar is a biosynthetic body with its own AI that takes           commands from the player and performs them in the game world. 
  
  - Scientist.h and Scientist.cpp - Class that represents the Non Player Characters (NPC's) in the first level of the game. Player must       speak and interact with the scientists to get objectives and progress through the level. 
  
  - Item.h and Item.cpp - Class that acts as a blueprint for items found and used in the gameworld. 
  
  - Map.h and Map.cpp - Header and source files containing functions related to generating and initializing the level map
  
  - SaveFile.h and SaveFile.cpp - Header and source files containing functions related to generating, saving and loading save files           (.txt)
  
  - Func.h and Func.cpp - Header and source files for general helper functions used in multiple source files throughout the program. 
  
  - Time is Fragile.soln - Visual studio solution file used to build project.
  
  
  How to build project: 
  - Clone repository
  - With all source files in folder, open Time is Fragile.soln
  - In Visual Studio, select "Release" version and then "Build Solution"
  - If using premade save files, make sure they are in the same folder as executable. 
  - Run Time is Fragile.exe
