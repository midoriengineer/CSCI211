#include <iostream>
using namespace std;

//----------------------------------------------------------------------
// FUNCTIONS
//----------------------------------------------------------------------

//move back to previous column
void backtrack(int &col){
	col--;
	if(col==-1) col= 0;
}

//print stable marriage
void print(int marriage[], int &count){
	cout << "Count: " << count << endl;
  cout << "Man     Woman" << endl;
  for(int i = 0; i < 3; i++){
    cout << i << "       " << marriage[i] << endl;
  }
	cout << endl;
	count++;
}

//Tests if marriage conflicts with other marriages
bool isStable(int marriage[], int col, int mp[][3], int wp[][3]) {

  //if past the first marriage, check if current marriage conflict with previous ones
  if(col > 0){

    //1. checks if a woman is married already
    for(int i = 0; i <col; i++) if(marriage[i] == marriage[col]) return false;

    //2. checks if current man likes previous women more than wife
    for(int i= 0; i <3; i++){
      if (mp[col][i] < mp[col][marriage[col]]){

				//find previous woman's husband
				for(int j=0; j<col;j++){
					if(marriage[j]==i) {
						//2a. checks if previous woman likes current man more than husband
						if(wp[i][col]< wp[i][j]) return false;
					}//if
				}//for

      }//if
    }//for

    //3. checks if current woman likes previous men more than husband
    for(int i= 0; i <col; i++){
      if (wp[marriage[col]][i] < wp[marriage[col]][col]){

        //3b. checks if previous man likes current woman more than wife
        if(mp[i][marriage[col]]< mp[i][marriage[i]]) return false;
      }//if
    }//for

  }//if

	return true;
}

//if marriage is stable, move to next column (man)
void nextCol(int marriage[], int &col, int &count){
	col++;
	if(col == 3) {
		print(marriage, count);
		backtrack(col);
		return;
	}
	marriage[col]=-1;
}

//if marriage is not stable, move to next row (woman)
void nextRow(int marriage[], int &col, int &count){
	marriage[col]++;
	if(marriage[col] ==3) {
		backtrack(col);
		if(marriage[col] ==3) return;
		else nextRow(marriage, col, count);
	}
}

//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------

int main(){

  //men's preference of women
  int mp[3][3]={{0,2,1},
                {0,2,1},
                {1,2,0}};

  //women's preference of men
  int wp[3][3]={{2,1,0},
                {0,1,2},
                {2,0,1}};

  //start off with no married pairs
  int marriage[3] = {-1};
  int col = -1;
  int count = 1;

  //loop places women in marriages (rows) by column
  while(col<3 && marriage[col]<3){

    nextCol(marriage,col,count);

    while(marriage[col]<3){
      //end loop if number of rows (women) exceeds 3
      if(marriage[col] ==3 ) break;
      nextRow(marriage,col, count);

      //go to next column (man) if marriage is stable
      if (isStable(marriage,col, mp, wp)) break;
    }
  }

  return 0;
}
