#include <stdbool.h> /* bool, false, true */
#include <stdio.h>   /* printf() */

#include <utils.h>   /* testFunc() */

int main(){

  // WELCOME MESSAGE
  printf("--- Sudoku Puzzle Solver ---\n");
  printf("\n");
  
  // STRUCTURE FOR HOLDING BOARD STATE
  // '0' REPRESENTS A BLANK SPACE
  int board[81] =
    {5,3,0,0,7,0,0,0,0,
     6,0,0,1,9,5,0,0,0,
     0,9,8,0,0,0,0,6,0,
     8,0,0,0,6,0,0,0,3,
     4,0,0,8,0,3,0,0,1,
     7,0,0,0,2,0,0,0,6,
     0,6,0,0,0,0,2,8,0,
     0,0,0,4,1,9,0,0,5,
     0,0,0,0,8,0,0,7,9};
  
  // STRUCTURE FOR HOLDING POSSIBLE
  // VALUES FOR EACH SPACE (INDEX BY ZERO)
  bool metaBoard[729];
  
  // INITIALIZE EVERY VALUE TO TRUE (POSSIBLE)
  for(int i = 0; i < 729; i++){ // for each space in the metaBoard
    metaBoard[i] = true;        // mark as true (possible)
  }

  // INITIALIZE PRE-FILLED SPACES
  for(int i = 0; i < 81; i++){      // for each space in the board
    if(board[i] != 0){               // if the space is not blank
      for(int j = 0; j < 9; j++){   // for the numbers associated with the i'th board space
	if(board[i] != j+1){         // if the metaBoard space is not the same as the number
	  metaBoard[i*9+j] = false; // mark the number as false (not possible)
	}
      }
    }
  }

  // SOLVE THE BOARD
  printBoard(board);
  int b;
  while(isBoardComplete(board) == false){      // while the board is not solved

    for(int row = 0; row < 9; row++){          // for every row in the board
      for(int col = 0; col < 9; col++){        // for every column in the row
	b = (row/3)*3 + (col/3);               // calculate the box that (row,col) is in

	if(board[row*9+col] != 0){             // if the space has been solved

	  for(int i = 0; i < 9; i++){          // for the 9 squares in row/column/box

	    if((row*9 + 1) != (row*9 + col)){  // exclude solved square
	      metaBoard[(row*9 + i)*9 + board[row*9 + col]-1] = false;
	    }

	    if((col + i*9) != (row*9 + col)){        // exclude solved square
	      metaBoard[(col + i*9)*9 + board[row*9 + col]-1] = false;
	    }

	    if((9*(b/3)*3 + (b%3)*3 + (i/3)*9 + (i%3)) != (row*9 + col)){ // exclude solved square
	      metaBoard[(9*(b/3)*3 + (b%3)*3 + (i/3)*9 + (i%3))*9 + board[row*9 + col]-1] = false;
	    }

	  }
	}
      }
    }
    updateBoard(board, metaBoard);
  }

  printBoard(board);
  return 0;

}
