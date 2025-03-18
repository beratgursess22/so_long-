# so_long

The so_long teaches how to develop a simple maze-like game where the player controls a character to collect items and reach the exit. The game is built using the MiniLibX library, which helps with basic graphics programming.

A-Main Components of the so_long Project

1-Map

The map is stored in a .ber file. This file defines the layout of the maze.
The map consists of different elements:
1 → Wall
0 → Path
P → Player's Starting Position
C → Collectible Items
E → Exit

2-Player Movement

The player can move using keyboard inputs (W, A, S, D).
The player cannot move through walls (1), and must navigate the paths (0).

3-Collectible Items (C)

The player must collect the C (collectible) items on the map.
After collecting all the items, the player must reach the E (exit) to complete the game.

4-MiniLibX Library

This project uses the MiniLibX library to create the game window and draw the map on the screen.
Sprites are used to visualize elements like walls, paths, the player, and collectibles.

5-Game Mechanics

The game counts and displays the total number of moves the player makes.
The game ends when the player collects all items and reaches the exit, and the number of moves is displayed.

B-How the so_long Project Works

Reading the Map File
The .ber file is read, and its contents are validated.
The map should have at least one player (P), one exit (E), and one collectible item (C).

C-Starting the Game

The game window is created using MiniLibX.
The map is rendered on the screen using sprite images (for walls, paths, the player, and collectibles).

D-Player Movement

The player moves based on keyboard inputs:
W for up, A for left, S for down, and D for right.
The player cannot move through walls and must navigate through paths to collect items and reach the exit.

E-Ending the Game

The game ends when the player collects all the items (C) and reaches the exit (E).
The total number of moves is displayed using printf().



