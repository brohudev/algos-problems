#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;
int sum(const vector<int>& array, int i, int j) { // little helper function
    int sum = 0;
    if(j == i+1) // base case
        return array[i];
    while(i < j){ // every other case
        sum += array[i];
        i++; 
    }
    if(j == array.size()-1)
        sum += array[j]; //grab the last on becase the middle case is not inclusive every time.
    return sum;
}
vector<int> getIndices(vector<int> array, int n, int k){
    vector<int> indices;
    int groupsize = n/k, 
        remainder = n%k, 
        currentIndex = 0;
    for(int i=1; i <= k; i++){
        int currentGroupSize = groupsize + (i <= remainder ? 1 : 0);
        for (int j = 1; j <= currentGroupSize; j++){
            currentIndex++;
        }
        indices.push_back(currentIndex-1);
    }
    return indices;
}
void backtrack(std::vector<int>& nums, vector<int>&currCombination, int index, int& result, int groups, vector<int> indices) {
    if(index >= nums.size()){
        int maxSubarray = INT_MIN;
        for (int i = 0; i < indices.size(); i++) {
            int startIndex = (i == 0) ? 0 : (indices[i - 1]); // set the starting index
            int endIndex = indices[i]; //set the ending index.
            int temp = sum(nums, startIndex, endIndex);
            if (temp > maxSubarray)
                maxSubarray = temp; //run the normal maxsubarray operation to find the max.
        }
        if(maxSubarray < result){
            result = maxSubarray;//if the max is lower than some other configuration,
                                // then we found a set of groups with a more "equalized" max.
                                //i.e this condition ensures we find the max st the sums across all subgroups are minimized.
        }
    }
    else{
        for (int j = index; j < nums.size(); j++) { //recursive case:
            swap(nums[index], nums[j]); //swap the ith index with jth index.
            backtrack(nums, currCombination, index + 1, result, groups, indices); //backtrack on the combination.
            swap(nums[index], nums[j]);//swap it back. 
            
            // int tempnum = nums.at(nums.front()+i); 
            // nums.erase(nums.begin()+i); //pop it so it doesnt interfere in recursion.
            // currCombination.push_back(tempnum); //add current element to combinations
            // backtrack(nums, currCombination, i + 1, result, groups, indices); //recursively generate combinations
            // nums.insert(nums.begin()+i,tempnum); //undo to try the next combination
        }
    }
}
int main(){
     int size, groups, result;
     cin >> size >> groups;
     vector<int> array, indices;
     for (int i = 0; i < size; ++i) {
          int element;
          cin >> element;
          array.push_back(element);
     }
    result = sum(array,0,array.size()-1); //set the result to the starting postion
    indices = getIndices(array, size, groups);
    vector<int> currCombination = {};
    backtrack(array, currCombination, 0, result, groups, indices);
    cout << result;
    return 0;
}
/*
backtrack(&arr, i, &result, k{groups})
     if i is on the last element of arr:
          int maxsubarray
          for all subarrays in arr (i.e for k times)
               sum = sum(subarray)
               if(sum > max):
                    max = sum
          if max < result:
               result = max
          return
     for all swaps possible from i to the end of arr:
          swap(i,j,arr)
          backtrack(arr, i+1, arr)
          swap(i,j,arr) // swap back
     return     
*/
// Function getIndices(array, n, k):
//     groupSize = n / k
//     remainder = n % k
//     groups = []
//     currentIndex = 0
//     for i from 1 to k:
//         group = []
//         currentGroupSize = groupSize + (i <= remainder ? 1 : 0)
// for j from 1 to currentGroupSize:
//             currentIndex += 1
//         # Save the index indicating the end of the current group
//         groupIndices.append(currentIndex - 1)
//     return groupIndices