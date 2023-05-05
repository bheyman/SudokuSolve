# SudokuSolve

SudokuSolve is a program which solves Sudoku puzzles.
The [Wikipedia article](en.wikipedia.org/wiki/Sudoku) for Sudoku explains the rules as follows:

> In classic Sudoku, the objective is to fill a 9 x 9 grid with digits so that each column, each row, and each of the nine 3 x 3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contains all the digits from 1 to 9.
> The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

Using these guidelines, the following rules can be drawn:

1. If there is a particular number in a row, no other space in that row can be that number
2. If there is a particular number in a column, no other space in that column can be that number
3. If there is a particular number in a box, no other space in that box can be that number

Therefore, one way to solve the puzzle is to keep track of all possible values for each space based on the spaces that are already filled out.
While impractical for a human user to do without scratch paper, a computer can easily perform this task.
