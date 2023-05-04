#include <stdbool.h> /* bool, false, true */
#include <stdio.h>   /* printf() */

#include <utils.h>

bool isBoardComplete(int board[]){

  for(int i = 0; i < 81; i++){ // for each space in the board
    if(board[i] == false){     // if the space is blank
      return false;            // board is not complete
    }
  }
  return true;                 // board is complete

}

void printBoard(int board[]){

  printf(" -----------------------------------\n");     // ceiling
	
  for (int i = 0; i < 9; i++){                          // for every row in the board
    printf("|  ");                                      // left wall
    for (int j = 0; j < 9; j++){                        // for every column in the row
      if (board[i*9+j]==0){                             // if the space is blank
	printf("   ");                                  // print a blank
      }else{		                                // if the space is a number
	printf("%d  ", board[i*9+j]);                   // print the number
      }				                        
      if (j==2 || j==5){                                // if this is the right edge of a section
	printf("|  ");                                  // middle walls
      }				                        
    }				                        
    printf("|\n");                                      // right wall
				                        
    if (i==2 || i==5){                                  // if this is the bottom edge of a section
      printf(" -----------------------------------\n"); // middle floor
    }
  }

  printf(" -----------------------------------\n");     // floor

}

void printMetaboard(bool metaBoard[]){

  for (int i = 0; i < 81; i++){        // for every space in the board
    printf("Space %02d: ", i);
    for (int j = 0; j < 9; j++){       // for every potential value of the space
      printf("%d ", metaBoard[i*9+j]); // print if this value is possible
    }
    printf("\n");
  }
}
  
void updateBoard(int board[], bool metaBoard[]){

  int sum;
  int location;

  for (int i = 0; i < 81; i++){     // for each space in the board
    sum = 0;                        // initialize to zero
    for(int j = 0; j < 9; j++){     // for each potential value of the space
      if(metaBoard[i*9+j] == true){ // if the value is possible
	sum++;                      // count the number of possible values
	location=j+1;               // record the possible value
      }
    }

    if(sum == 1){                   // if there is only one possible value
      board[i] = location;          // set the space in the board
    }
  }
}
