# Minesweeper
This is a personal project written mostly in C++. There is a Makefile and a small amount of BASH scripting for added functionality. 

To start the game, navigate to the Minesweeper directory housing all files, and type "make" in your terminal. When done playing, type "make clean" to remove the object files. 

The goal of this project is to recreate the desktop game Minesweeper. 

This project is implemented to execute in a UNIX terminal, preferably one that supports ANSI escape sequences, so that the game can run in color.
(if your terminal does not support ANSI escape sequences, enter "0" after starting this game)

Due to the nature of terminal interaction, user input must come from the keyboard.

The user can select between Easy (9x9, 10 mines), Medium (16x16, 40 mines), and Hard (25x25, 99 mines) difficulties.

Instructions for user input are given at the beginning of the game. 
