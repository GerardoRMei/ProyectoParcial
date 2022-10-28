# ProyectoParcial

Summary

The program works on the terminal, your character will start at the bottom of the GameBoard. You are tasked to reach the safe spot identifiable with a “0”
before you ran out of turns (movements). Also avoid the enemies, if they hit you once it will end in a gameover. On another note, there are coins ($) spread around the map. These are optional which means if you finish without taking a single coin you will not lose, however it will reduce your exoponentially your score. 

The program implements two classes one for special zones and other for entities. The coins and the safespot use the special zone class and it registers two integer values, one for the X location and other for the Y location. It also has a string to represent the symbols and boolean variable to check if the object is reached. The second class is similar, but it adds a function that allows the position of the entities to be changed. 

The board is made on a vector of vectors in order to make the matrix like figure that I wanted the board to have, it also helps me to give a limit to the map, so that the enemies and the player do not clip out of the borders.

Threads are used for the entities actions and the timer, I decided to use threads for this mainly becuase it allows the program to make the three things at the same time.

Finally I use a map to register the scores with a "username". This makes the username (a string value) to be the key of each element of the map. If the username is registered it will check if the score is higher or lower. In case of being higher it will update the value to the new one. Finally it will be sorted in a descending order.

The user aswell as the scores are registered on files, they appear in a way that it resembles a board of an arcade.

Link: https://youtu.be/GUao4ccTb9U 
