# PSU_2016_navy

Navy is one of the first year project in Epitech. <br/>
It is a battleship game between two terminals on one PC communicating with signals. <br/>
In this game there is 4 ships. One of size 2, One of size 3, one of size 4 and one of size 5. <br/>

![navy image](/ressources/navy.png)

## Getting Started

This game is programmed in C on a Linux environment.

### Prerequisites

To compile we are using gcc.<br/>

### Installing

To install the game please use the Makefile to compile the game.
 
```
$> make
```

At the end you should have a "navy" binary in your current folder.

## Running the programm

To run the first player:<br/>

```
$> ./navy {navy_positions}
my_pid: xxxxx
waiting for enemy connection...
```
To run the second player:<br/>

```
$> ./navy {first_player_pid} {navy_positions}
my_pid: 14528
successfully connected
...
```

Replace {navy_positions} by a file containing the position of ships. [Creating ships file](#creating-ships-file)<br/>
Replace {first_player_pid} by the number given when launching the first player<br/>

If you want to see the usage:
```
$> ./navy -h
USAGE
		./navy [first_player_pid] navy_positions

DESCRIPTION
		first_player_pid	only for the 2nd player.  pid of the first player.
		navy_positions		file representing the positions of the ships.
```

## Creating ships file

You can create your own ship file, to put your ships as you want. <br/>
You can name it as you want and put the file in the folder "ships" <br/><br/>
A line in the file must have this format :
```
{length}:{position 1}:{position 2}
```
You must have 4 line in this file, one for each length of ship.<br/>
The {length} correspond to the length of the ship you want.<br/>
The {position 1} correspond to the first coordinate of the ship.<br/>
The {position 2} correspond to the second coordinate of the ship.<br/><br/>

Here is an example of correct file :
```
3:H1:H3
4:E6:H6
5:B1:F1
2:C4:D4
```

## Authors

* **Sébastien Tan** - *Developer* - [Setanas](https://github.com/Setanas)


## Collaborater

* **Nicolas DEVIERS** - *Developer*