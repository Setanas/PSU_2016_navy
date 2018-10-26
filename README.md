# Navy
> TAN_S

Battleship game with two terminals on one PC communicating with signals.
Project in collaboration with Nicolas DEVIERS

## Example
First terminal : `./navy "name of the file with your ship's position".`

Second terminal : `./navy "pid of the first terminal" "name of the file with your ship's position".`

The map goes from A1 to H7.
Example of file with ships:
```
2:C4:D4
3:H1:H3
4:E6:H6
5:B1:F1
```
length:coord1:coord2.

Only 4 ships
```
1 of length 2
1 of length 3
1 of length 4
1 of length 5
```
