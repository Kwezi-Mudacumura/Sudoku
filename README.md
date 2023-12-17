<h1>9x9 sudoku program</h1>
<p>A Sudoku is a number-placement puzzle. An n×n grid has n rows, n columns and n blocks (which is made of
a k × k grid of cells, where n = k*2). Some cells will have numbers already, and the goal is to place a number
from {1, . . . , n} into each cell, such that each row, column and block contains every number once and only
once. A valid Sudoku puzzle should have one unique solution.
</br></br>
Example of 9x9 sudoku:<a href="https://en.wikipedia.org/wiki/Sudoku">Exampleof9x9sudoku</a> </br></br>
For example, in Figure above on wikipedia, there are 9 rows and columns and 9 3 × 3 blocks. There are some cells with
numbers in them already. The goal is to fill each empty cell with a number between 1 and 9 (inclusive). We can
place 4 into the cell in the fourth row and first column (marked with a dot). This is a valid move because the
relevant row and column do not currently contain a 4. The 3 × 3 block needs a 4, but there are already 4s in the
fifth and sixth rows. Similarly, it cannot be placed to the right of the 7 as there is already a 4 in that column.
There are several logical techniques to narrow down potential values for a cell and solve a given Sudoku.
However, in this program, you will implement a Depth First Search(DFS) using recursion was used. A DFS is a backtracking
algorithm where we make a decision and stick with it until we either solve the problem or discover that it was
an incorrect choice. If it was incorrect, we backtrack or undo that decision, make a different one, and then try
again. </br>
Please note:The Sudoku will either have a unique or no solution.</p>
</br>
<p>
Input:</br>
This program read a Sudoku from stdin (using cin). It reads n integers, each separated by
spaces. It contains values in {0, 1, . . . , n}. If a cell contains a 0 then it will be treated that cell as blank. The program handles Sudoku of one size only thus far:
  <ul>
<li> 9 × 9 – {0, 1, . . . , 9},</li>
  </ul>
</br>

The input is always be valid, and the program doesnt handle special cases with strange whitespace, etc.
</br>
Example of input:</br>
0 4 0 0 0 0 1 7 9</br>
0 0 2 0 0 8 0 5 4</br>
0 0 6 0 0 5 0 0 8</br>
0 8 0 0 7 0 9 1 0</br>
0 5 0 0 9 0 0 3 0</br>
0 1 9 0 6 0 0 4 0</br>
3 0 0 4 0 0 7 0 0</br>
5 7 0 1 0 0 2 0 0</br>
9 2 8 0 0 0 0 6 0</br>
</br>
Output:</br>
The program outputs the solved Sudoku with all the values separated by spaces, or if there is no solution, the text No Solution is outputted.
</br>Example of output:</br>
8 4 5 6 3 2 1 7 9</br>
7 3 2 9 1 8 6 5 4</br>
1 9 6 7 4 5 3 2 8</br>
6 8 3 5 7 4 9 1 2</br>
4 5 7 2 9 1 8 3 6</br>
2 1 9 8 6 3 5 4 7</br>
3 6 1 4 2 9 7 8 5</br>
5 7 4 1 8 6 2 9 3</br>
9 2 8 3 5 7 4 6 1</br>
</br> or </br>No Solution




  
</p>
