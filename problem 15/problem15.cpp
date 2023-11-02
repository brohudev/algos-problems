#include <iostream>
#include <string>
using namespace std;

int staircombinations(int stairheight, int maxstep){
     if (stairheight  <= 0)
          return 1; // base case is leaf node. i.e a complete traversal through all stairs
     else if (stairheight < maxstep)
          maxstep = stairheight;
     int numstaircombinations = 0; 
     for (int i = 1; i <= maxstep; i++)
          numstaircombinations += staircombinations(stairheight-i, maxstep);
     return numstaircombinations;
};
int main(){
     int maxstep, stairheight;
     cin >> stairheight; cin >>maxstep;
     cout << staircombinations(stairheight, maxstep); //run the function
     return 0;
}

/*function(stairheight, maxstep)
     if(stairheight <=0)
          return 1 //base case
     else if (stairheight < maxstep)
          maxstep = stairheight
     num climbperms
     for i in range (maxstep)
          climbperms += f(stairheight-i, maxstep)
     return temp*/