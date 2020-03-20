# Sudoku Solver
The program is written in C for high efficiency so that the sudoku puzzles can be solved as fast as possible.

## Disclamer
I am just making this code for fun.  You may use and modify without permission, although please do not reupload my files anywhere else for redistribution.

## Used terminology
- **Cell** A cell is a single square which can contain a value or pencil marks.
- **Block** A block is a 3x3 group of cells which see each other.
- **Row** A row is a group of 9 cells which see each other and are horizontally aligned.
- **Column** A column is a group of 9 cells which see each other and are vertically aligned.
- **Pencil Marks** Pencil marks represent the possible values a cell can hold.

## Goals
- [ ] Set up board structure
- [ ] Be able to print the sudoku board.
- [ ] Be able to find all the pencil marks in each cell.
- [ ] Solve cells with only one possible value.
- [ ] Solve hidden singles.
- [ ] Solve locking candidate type 1 (pointing).
- [ ] Solve locking candidate type 2 (claiming).
- [ ] Solve hidden pairs.
- [ ] Solve hidden triples.
- [ ] Solve hidden quadruples.
- [ ] Solve via brute force.
## Board Structure
### Cell
To save space, each cell will contian two values; the actual value of the square (0 if no value has been assigned), and the candidates (stored as a short, but values are stored as individual bits.)
### Row
Each row structure contains 9 pointers to each of the cells.
### Column
Each column structure contains 9 pointers to each of the cells.
### Block
Each block structure contains 9 pointers to each of the cells.
### General Structure
Since brute force requires a lot of back and forth motion, all of the cells will be next to each other.  That way, to speed up incrementing around the board, all that the program needs is the location in memory of the first cell.



## References

- Hobiger, B. (n.d.). HoDoKu - Sudoku generator/solver/trainer/analyzer. Retrieved March 19, 2020, from http://hodoku.sourceforge.net/en/index.php
