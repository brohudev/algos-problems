#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
struct object {
     int n;
     int k_1_based_index;
     int n_0_based_index;
     bool n_found;
     object(int num) : n(num), n_found(false), k_1_based_index(0), n_0_based_index(-1) {}
};

void find(vector<int> &nums, object &obj, int begin, int end){
     int mid = (begin + end) / 2; // calculate midpoint
     
     if(begin >= end) {
          if(nums[mid] == obj.n) { //set n index if this value is n. basically search for n in the base case of mergesort
               obj.n_found = true;
               obj.n_0_based_index = mid;
          }
         return;  // return for merge and for search...
     }

     find(nums, obj, mid + 1, end);  // recursively Search and mergesort in the right half
     find(nums, obj, begin, mid);  // recursively Search and mergesort in the left half
     
     if(nums[mid] > nums[mid+1]){ //found our k_1! there is no merge since there is only one array and indices
          obj.k_1_based_index = mid+1;
          return;
     }
     return; //return for all cases where nums[mid] < nums[mid+1] since we dont do anything in that case. 
}
int main(){
     string input; 
     getline(cin,input);
     istringstream iss(input);
     vector<int> nums;
     int n;
     while (iss >> n) {// input into nums
          nums.push_back(n);
     }
     cin >> n;
     object obj(n); // create a struct
     find(nums, obj, 0, nums.size() - 1); // Run the function
     cout << obj.k_1_based_index << "\n" << obj.n_0_based_index; // print output from the struct
     return 0;
}