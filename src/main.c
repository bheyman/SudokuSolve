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
    if(grid[i] != 0){               // if the space is not blank
      for(int j = 0; j < 9; j++){   // for the numbers associated with the i'th board space
	if(grid[i] != j+1){         // if the metaBoard space is not the same as the number
	  metaBoard[i*9+j] = false; // mark the number as false (not possible)
	}
      }
    }
  }

  /* SOLVE THE BOARD */
  
  testFunc();
    
  return 0;

}
