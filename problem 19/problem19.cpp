#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
int rachelPoints;
int robertPoints;

int helper(vector<int>& subArray1,vector<int>& subArray2) {// subArray1 should always be a left subarray and subArray2 should always br a right subarray.
     int index = 0, temp_score = 0, final_score = 0;
     while(index < subArray2.size()){
          while (temp_score < subArray1.size() && subArray2[index] > subArray1[temp_score])
            temp_score++;
          final_score+= temp_score;
          index++;
     }
     return final_score;
}

void merge(vector<int>& robertArray, vector<int>& robertleft, vector<int>& robertright,
               vector<int>& rachelArray, vector<int>& rachelleft,vector<int>& rachelright){
     
     if (robertArray.size() != robertleft.size() + robertright.size()) return; // sanity check
     if (rachelArray.size() != rachelleft.size() + rachelright.size()) return; // sanity check
     
     //*merge robertarray:
     size_t rob_i=0, rob_j=0, rob_k=0;
     size_t rach_i=0, rach_j=0, rach_k=0;

     if (rob_i < robertleft.size() && rob_j < robertright.size()) // this is so it only runs before we merge
        robertPoints+= helper(rachelleft, robertright);
//     Repeat this if for rachelPoints, you'll be changing the indicies and left/right subarrays accordingly
     if (rob_i < rachelleft.size() && rob_j < rachelright.size()) // this is so it only runs before we merge
        rachelPoints+= helper(robertleft, rachelright);
  
     while (rob_i < robertleft.size() && rob_j < robertright.size()) {
          if (robertleft[rob_i] <= robertright[rob_j]) //* stable, if '<' is used then unstable
               robertArray[rob_k++] = robertleft[rob_i++];
          else
               robertArray[rob_k++] = robertright[rob_j++];
     }
     while (rob_i < robertleft.size()) 
          robertArray[rob_k++] = robertleft[rob_i++];
     while (rob_j < robertright.size()) 
          robertArray[rob_k++] = robertright[rob_j++];

     //* merge rachelarray:
     while (rach_i < rachelleft.size() && rach_j < rachelright.size()) {
          if (rachelleft[rach_i] <= rachelright[rach_j]) //* stable, if '<' is used then unstable
               rachelArray[rach_k++] = rachelleft[rach_i++];
          else
               rachelArray[rach_k++] = rachelright[rach_j++];
     }
     while (rach_i < rachelleft.size()) 
          rachelArray[rach_k++] = rachelleft[rach_i++];
     while (rach_j < rachelright.size()) 
          rachelArray[rach_k++] = rachelright[rach_j++];
}

/**
* ---------------------------------------------------------------------------
* The Merge Sort algorithm
* - create a copy of the left half, and a copy of the right half
* - recursively sort the left half and the right half
* - then merge the two halves
* ---------------------------------------------------------------------------
*/
void mergeSort(vector<int>& robertArray, vector<int>& rachelArray) {
     size_t rob_n = robertArray.size();
     size_t rach_n = rachelArray.size();
     if (rach_n <= 1) return;

     vector<int> robertleft(robertArray.begin(), robertArray.begin()+rob_n/2);
     vector<int> robertright(robertArray.begin()+rob_n/2, robertArray.end());

     vector<int> rachelleft(rachelArray.begin(), rachelArray.begin()+rach_n/2);
     vector<int> rachelright(rachelArray.begin()+rach_n/2, rachelArray.end());
     //recursively sort the two sides of both arrays
     mergeSort(robertleft,rachelleft);
     mergeSort(robertright,rachelright);
     //merge both the arrays.
     merge(robertArray, robertleft, robertright, rachelArray, rachelleft, rachelright);
}

int main(){
     string input;
     getline(cin, input);
     istringstream iss(input);
     vector<int> robertArray, rachelArray;
     // fill arrays with stdin
     int num;
     while (iss >> num) {//fill in robertarray
          robertArray.push_back(num);
     }
     getline(cin, input); num=0;
     istringstream iss2(input);
     while (iss2 >> num) { //fill in rachel array
          rachelArray.push_back(num);
     }
     mergeSort(robertArray, rachelArray); //do the magic
// * so the below chunk of commented code is mainly to make sure mergesort works as intended. 
// * it was removed in the submission since that only requires one cout. 
//      for (int element : robertArray) {
//         std::cout << element << " ";
//     }
//     cout<<endl;
//     for (int element : rachelArray) {
//         std::cout << element << " ";
//     } cout <<endl;
     // output the result
     cout << robertPoints << " "<< rachelPoints<<endl;
     return 0;
}