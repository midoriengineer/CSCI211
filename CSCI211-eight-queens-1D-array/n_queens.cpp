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

//print solutions number
void print(int q[], int &count, int n){
	cout << "There are " << count << " solutions to the " << n << " queens problem" << endl;
}

//Tests if queen conflicts with other queens
bool rowDiagonalTest(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[c] == q[i] or (c - i) == abs(q[c] - q[i])) return false;
	}
	return true;
}

//if queen is placed safely, move to next column
void nextCol(int q[], int &col, int &count, int n){
	col++;
	if(col ==n) {
		//print(q, count);
		count++;
		backtrack(col);
		return;
	}
	q[col]=-1;
}

//if queen is placed safely, move to next row in column
void nextRow(int q[], int &col, int &count, int n){
	q[col]++;
	if(q[col] ==n) {
		backtrack(col);
		if(q[col] ==n) return;
		else nextRow(q,col,count,n);
	}
}

//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------

int main() {

		int col;
		int count;

		int n;
		cout << "Enter the board size: ";
		cin >> n;

		//loop through all board sizes from 1x1 through nxn
		for(int temp_n = 1; temp_n <= n; temp_n++){

			//create empty board
			count=0;
			col = -1;
			int* q = new int[temp_n];
			for(int i =0; i< temp_n; i++) q[i] = -1;

			//loop places queens in rows by column
			while(col < temp_n && q[col] < temp_n){

				nextCol(q,col,count,temp_n);

				while(q[col] < temp_n){
					//end loop for rows if number of rows exceeds 8
					if(q[col] == temp_n ) break;
					nextRow(q,col,count,temp_n);

					//go to next column if Queen placement passes row & diagonal text
					if (rowDiagonalTest(q,col)) break;
				}
			}//while loop

			//print and reset board to prepare for new board size
			print(q, count,temp_n);
			delete [] q;

		}//for loop

		return 0;
}//main
