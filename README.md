# Sudoku Solver
A c++ sudoku solver.

### Build

Clone this repo and build the binaries with:

```bash
git clone https://github.com/GabrieleMaurina/sudoku.git
cd sudoku
make
```

### Usage

You can run a simple demo that will solve 20 boards with:

`./demo`

Or you can run just the solver with:

`./sudoku`

The solver itself expects a board as a string from the **stdin** and spits out the solution as a string to the **stdout**. The easiest way to do it is to get the board from a file like so:

**board.txt**
```
0 0 0 0 0 5 0 7 0
1 0 0 0 0 0 0 4 9
5 7 2 0 0 0 0 0 0
0 0 8 0 6 0 0 0 7
0 0 0 0 0 2 3 0 6
9 0 0 5 0 7 0 0 0
7 0 0 0 0 9 0 0 5
0 9 0 0 5 0 0 0 0
0 0 0 0 0 3 0 2 8
```

Then run: `./sudoku < board.txt > sol.txt`

You will get:

**sol.txt**
```
8 4 9 3 1 5 6 7 2
1 3 6 2 7 8 5 4 9
5 7 2 4 9 6 8 3 1
3 2 8 9 6 4 1 5 7
4 5 7 1 8 2 3 9 6
9 6 1 5 3 7 2 8 4
7 8 3 6 2 9 4 1 5
2 9 4 8 5 1 7 6 3
6 1 5 7 4 3 9 2 8
```

### Board

The board is just a sequence of characters, where 0 denotes an empty cell and the numbers 1-9 denote the actual numbers from 1 to 9. **Any other character is ignored.** The numbers fill the board left to right, top to bottom.
