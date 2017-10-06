# filler

Filler is a board game where players take turns playing shapes on a 2D grid.
Each shape must be played next to another one.
Playing a shape score as many points as the number of squares it occupies.
When both players can't play their given shape, game is over and the player with the most points win.

## How to use :

The game itself sits in an executable in the resources folder:

![](https://i.imgur.com/pPgUTkW.png)

The code in this repository compiles a bot that plays the game.  
After executing `make`, it should sit in `players/mperronc.filler`

The goal of this project was to beat the other `.filler` bots

## AI behavior :

On its turn, my bot cuts the board in sub squares, and weighs them :
+ An empty square is worth lots of points
+ An enemy square is worth some points
+ A square ofmine is worth negative points

The idea is to expand towards empty spots and avoid slow moves.  

After weighing the squares I choose the most valued one and play at the closest valid position.  

## Example :

![](https://i.imgur.com/Nq0xdEN.gif)
