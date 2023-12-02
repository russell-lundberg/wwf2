# wwf2
The code in this repository creates an executable that generates a list of valid American English words from an inputted list of alphabetic characters. The project might be called a "cheat" for the game Words With Friends, WWF.

Presently, the initial v0.0.1 release accepts letters using options "-r" (the "rack") and "-e" ("extension"), and allows a single blank ("-b") or 2 blanks ("-B") to be included. All possible permutations of the inputted letters are compared to the dictionary and the list of permutations matched in the dictionary is displayed. Presently the displayed list is ordered by ascending word length. (My next effort will be to score each word so that the list may be ordered by ascending score.)

The Makefile has been setup for Linux and Mac, although presently I have not yet been successful using the Boost libraries on Mac. Regardless, you'll need to edit the Makefile for your environment and paths.

Additional options I hope to implement include filtering results by regex, searching the dictionary for a regex, allowing a group of 2 or more letters to be added as a block to the possible permutations. 

This project is my effort to learn the C++ language. Myself, I identify as a Perl programmer, and created this code in Perl many years ago. But I've long wanted to learn C++ for graphics programming, and this project seemed a relatively practical task for advancing that objective.
