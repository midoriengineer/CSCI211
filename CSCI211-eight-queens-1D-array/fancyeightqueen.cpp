#include <iostream>
#include <cmath>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------
// GLOBAL VARIABLES
//--------------------------------------------------------------------------------------------------------------------------------

typedef string box[5][11];

//Board & box setup
int i, j, k, l;
box bb, wb, bbq, wbq, *board[8][8];

//--------------------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------

//points the all boxes on the board back to empty ones
void resetBoard(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++) {
				if((i + j)%2 == 0)
						board[i][j] = &wb;
				else
						board[i][j] = &bb;
		}
	}
}

//points the all queens to the board[8][8]
void setBoard(int q[]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++) {
			if(q[j]==i){
				if((i + j)%2 == 0)
						board[i][j] = &bbq;
				else
						board[i][j] = &wbq;
			}
		}
	}
}

//move back to previous column
void backtrack(int &col){
	col--;
	if(col==-1) col= 0;
}

//print chessboard
void print(int q[], int &count)
	{
	//put queens on board
	setBoard(q);

	cout << "Count: " << count << endl;

  // First print upper border
  cout << " ";
  for(int i = 0; i < 11*8 + 1; i++)
      cout << '_';
  cout << endl;

  // Now print the board
  for(int i = 0; i < 8; i++)
      for(int k = 0; k < 5; k++) {
          cout << " " << "│"; // Print left border
          for(int j = 0; j < 8; j++)
              for(int l = 0; l < 11; l++)
                  cout << (*board[i][j])[k][l];
          cout << "│" << endl; // At end of line print bar and then newline
      }

  // Before exiting, print lower border
  cout << " ";
  for(int i = 0; i < 11*8 + 1; i++)
      cout << "─";
  cout << endl << endl << endl;

	//clear queens off of board
	resetBoard();

	count++;
}

//Tests if queen conflicts with other queens
bool rowDiagonalTest(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[c] == q[i] or (c - i) == abs(q[c] - q[i])) return false;
	}
	return true;
}

//if queen is placed safely, move to next column
void nextCol(int q[], int &col, int &count)
	{
	col++;
	if(col ==8) {
		print(q, count);
		backtrack(col);
		return;
	}
	q[col]=-1;
}

//if queen is placed safely, move to next row in column
void nextRow(int q[], int &col, int &count){
	q[col]++;
	if(q[col] ==8) {
		backtrack(col);
		if(q[col] ==8) return;
		else nextRow(q,col, count);
	}
}

//--------------------------------------------------------------------------------------------------------------------------------
// MAIN
//--------------------------------------------------------------------------------------------------------------------------------

int main() {

    //No rows sets for each queen
    int q[8] = {-1};
    int col = -1;
    int count = 1;



    //------------------------------------------------------------------------------
    // Fill in board boxes in board[8][8]
    //------------------------------------------------------------------------------

    // Fill in bb = black box, and wb = white box
    for(i = 0; i < 5; i++){
			for(j = 0; j < 11; j++) {
					wb[i][j] = " ";
					bb[i][j] = "█";
			}
		}

    //fill in crowns for bbq = queen w/black bg, and  wbq = queen w/white bg
    for(i = 0; i < 5; i++){
			for(j = 0; j < 11; j++) {

					if((i==1 && j==2) || (i==2 && j==2) || (i==3 && j==2) ||
						(i==3 && j==3) || (i==3 && j==4) || (i==1 && j==5) ||
						(i==2 && j==5) || (i==3 && j==5) || (i==3 && j==6) ||
						(i==3 && j==7) || (i==1 && j==8) || (i==2 && j==8) ||
						(i==3 && j==8)) wbq[i][j] = " ";
					else wbq[i][j] = "█";

					if((i==1 && j==2) || (i==2 && j==2) || (i==3 && j==2) ||
						(i==3 && j==3) || (i==3 && j==4) || (i==1 && j==5) ||
						(i==2 && j==5) || (i==3 && j==5) || (i==3 && j==6) ||
						(i==3 && j==7) || (i==1 && j==8) || (i==2 && j==8) ||
						(i==3 && j==8)) bbq[i][j] = "█";
					else bbq[i][j] = " ";
			}
		}


    // Fill board with pointers to bb and wb in alternate positions
    resetBoard();

    //------------------------------------------------------------------------------
    // Determine & print the placement of the queens on the board in q[8]
    //------------------------------------------------------------------------------

    //loop places queens in rows by column
    while(col<8){

			if(q[col] ==8 ) break;
      nextCol(q,col,count);

      while(q[col]<8){
        //end loop for rows if number of rows exceeds 8
        if(q[col] ==8 ) break;

        nextRow(q,col, count);

        //go to next column if Queen placement passes row & diagonal text
        if (rowDiagonalTest(q,col)) {
					break;
				}
      }
    }

    return 0;
}
