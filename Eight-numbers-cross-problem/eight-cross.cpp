
//CSCI 211 Naomi and Sayeed Assignment 5
//----------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

//----------------------------------------------------------------------
// FUNCTIONS
//----------------------------------------------------------------------

//prints the cross
void print(int cross[]) {
  for(int i = 0; i <8; i++){
    if(i==0 || i==6) cout << "  " << cross[i];
    else if(i==1 || i==7) cout << " " << cross[i] << endl;
    else if(i==5) cout << cross[i] << " " << endl;
    else cout << cross[i] << " ";
  }
  cout << endl;
}

//returns to the previous box in the cross
void backtrack(int &currentBox){
  currentBox--;
  if(currentBox == -1) currentBox = 0;
}

//proceeds to the next box in the cross
void nextBox(int cross[], int &currentBox){
  currentBox++;

  if(currentBox == 8){
    print(cross);
    backtrack(currentBox);
    return;
  }
  cross[currentBox] = 0;
}

//proceeds to the next sequential number for the current cross box
void nextSeqNumber(int cross[], int &currentBox){
  cross[currentBox]++;
  if(cross[currentBox] == 9) {
    backtrack(currentBox);
    //if(cross[currentBox] == 8) return;
    nextSeqNumber(cross, currentBox);
  }
}

//checks if adjacent boxes are NOT the same or in sequential order and is the current number is already on the cross
bool sequentialCheck(int cross[], int adjBox[][5], int &currentBox){

  int i = 0;

  //is the number already on the cross?
  if(currentBox != 0){
    for(int j = currentBox-1; j > -1; j--){
    if(cross[currentBox] == cross[j]) return false;
    }
  }

  //is the adjacent number sequential?
  while(adjBox[currentBox][i] != -1){
    if(abs(cross[currentBox]-cross[adjBox[currentBox][i]]) ==1) return false;
    i++;
  }
  return true;
}

//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------

int main(){

  int cross[8];
  cross[0] =0;
  int currentBox= -1;

  //boxes that are adjecent to the row index number in the cross. -1 means there is no more adjacent boxes
  int adjBoxes[8][5] = {{-1},
                        {0,-1},
                        {0,-1},
                        {0,1,2,-1},
                        {0,1,3,-1},
                        {1,4,-1},
                        {2,3,4,-1},
                        {3,4,5,6,-1}};

  //looping through each adjecent box to check if the current box is valid number
  while(cross[currentBox] < 9 && currentBox < 8){
    nextBox(cross, currentBox);

    while(cross[currentBox] <9){

      nextSeqNumber(cross, currentBox);
      if(cross[currentBox]==9) break;

      if(sequentialCheck(cross, adjBoxes,currentBox)) break;
    }
  }
  return 0;
}
