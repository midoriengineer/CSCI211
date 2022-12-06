#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> tower[3]; //three towers A,B,C represented as an array of 3 vectors
  int n, candidate, to, from, move; //move counts the move number
  cout << "please enter a number of rings to move: ";
  cin >> n;
  cout << endl;

  //initialize the three towers
  for(int i = n+1; i>=1; i--)
    tower[0].push_back(i);
  tower[1].push_back(n+1);
  tower[2].push_back(n+1);

  //initialize towers and candidate
  from=0;
  to=0;
  candidate=1;
  move=0;
  nOdd; //is n odd???

  //---------------------------------------------------------------

  // checks if n is odd or even to determine the starting "to" place
  if(n%2 == 1){
    to = 1;
    nOdd=true;
  }
  else if(n%2 == 1){
    to = 2;
    nOdd=false;
  }

  //---------------------------------------------------------------

  while(tower[1].size()<n+1){ //there are still rings to transfer to tower B = tower[1]
    //print
    cout <<"move no. " << ++move << ": Transfer ring " << candidate
    << " from tower " << char(from+65)<< " to tower " << char(to+65) << endl;

    //moves disk in the "from tower" to the "to tower" and then removes it from "from tower"
    tower[to].push_back(tower[from].back());
    tower[from].pop_back();

    // get next "from tower" which is the smallest disk that was not moved last turn
    if(tower[(to+1)%3].back() < tower[(to+2)%3].back())
      from=(to+1)%3;
    else
      from=(to+2)%3;

    //get next "to tower" based on if n is odd---------------
    if(nOdd){
      // get next "to tower" which is the next closest tower available to the candidate
      if()
        to=0;
      else
        t0=0;
    }
    //get next "to tower" based on id n is even--------------
    else{
      // get next "to tower"
      if()
        to=0;
      else
        t0=0;
    }

    //get next candidate from the top of the "from tower"
    candidate = tower[from].back();

  }// end while loop

  return 0;
}
