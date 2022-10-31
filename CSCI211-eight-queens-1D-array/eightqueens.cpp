//CSCI 211 Naomi and Sayeed Assignment 4
//----------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

//----------------------------------------------------------------------
// FUNCTIONS
//----------------------------------------------------------------------

//move back to previous column
void backtrack(int &col){
	col--;
	if(col==-1) col= 0;
}

//print chessboard
void print(int q[], int &count){
	cout << "Count: " << count << endl;
	for(int r =0; r < 8; r++){
		for(int c=0; c<8; c++){
			if(q[c] == r) cout << "O  ";
			else cout << "X  ";
		}
		cout << endl;
	}
	cout << endl;
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
void nextCol(int q[], int &col, int &count){
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

//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------

int main() {

    //No rows sets for each queen
    int q[8] = {-1};
    int col = -1;
    int count = 1;

    //loop places queens in rows by column
    while(col<8 && q[col]<8){

	    nextCol(q,col,count);

	    while(q[col]<8){
		    //end loop for rows if number of rows exceeds 8
		    if(q[col] ==8 ) break;
		    nextRow(q,col, count);

		    //go to next column if Queen placement passes row & diagonal text
		    if (rowDiagonalTest(q,col)) break;
	    }
    }
		return 0;
}//main
