#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int countDigits(int n) {//helper function to calculate number of digits
     if (n == 0) {
          return 1; // Special case for handling n = 0
     }
     return static_cast<int>(log10(n)) + 1;
}
int getdigitat(int num, int index){
     string number = to_string(num);
     return stoi(number.substr(index,1));
}
int increment(int number, int index){ // helper function to increment the digit at index
     string numStr = to_string(number);
     char digit = numStr[index-1];
     digit = digit + 1;// Decrement the digit.
     numStr[index] = digit;// Replace the digit at the given index with the decremented digit.
     int incremented_number = std::stoi(numStr); // Convert the string back to a number.
     return incremented_number;
}
int decrement(int number, int index){
     string numStr = to_string(number);
     char digit = numStr[index-1];
     digit = digit - 1;// Decrement the digit.
     numStr[index] = digit; // Replace the digit at the given index with the decremented digit.
     int decremented_number = std::stoi(numStr);// Convert the string back to a number.
     return decremented_number;
}
int getlength(int num){ // helper to return length of num
     if(num == 0)
          return 0;
     else if(num == 1)
          return 1;
     return ceil(log10(num));
}
void stepperfunction(vector<int> &nums, int num, int high, int digit_curr, int digit_total){
     if(num > high)
          return; //base case: num out of bounds
     if(digit_curr >= (digit_total)){
          nums.push_back(num); //everything goes well the end number is an answer
          return;
     }
     if(digit_curr >= (getlength(num)-1) && digit_curr < digit_total){
          nums.push_back(num); // valid number, just theres a magnitude more left to search
          num *= 10;
     }
     if(getdigitat(num, digit_curr)-1 >= 0){// arithmetic violation. can't have a (-1) digit
          digit_curr+=1; // start working on the next digit
          int decremented_num = decrement(num, digit_curr);
          stepperfunction(nums,decremented_num, high, digit_curr, digit_total); // recurse on the num with decremented next digit

     }
     if(getdigitat(num, digit_curr)+1 <= 9){
          digit_curr+=1; // start working on the next digit
          int incremented_num = increment(num, digit_curr);
          stepperfunction(nums,incremented_num, high, digit_curr, digit_total); // recurse on the num with incremented next digit
     }
     return; //exit. dont do anything in the case where the digit goes out of bound.
}
int main() {
     int low, high;
     cin >> low; cin >> high; //input bounds
     // cout << increment(high, 2);
     vector<int> nums; //container for answers
     if(low < 10){ // take care of the single digit case...
          if(high >= 10) // only single digits
               for(int i = low; i<= 10 ; i++)
                    cout << i << " ";
          low = 11; // update low
     }
     stepperfunction(nums, low, high, 0, countDigits(high));
     if(!nums.empty())
     for(auto num : nums){
          cout << num <<" ";
     }
     return 0;
}
/* function(vector nums, num, high, digit_total, digit_curr)
     *f(num > high) //trivial base case: violation of constraint
          return
     
     *if(digit_curr == digit_total) //! there might be an error here. function might overshoot. 
          nums.pushback(num); return; //base case: answer is found
     
     *if(num.at(digit_curr++) == 0)
          return; //arithmetic violation: can't have a -1 digit. 
     *num.at(digit_curr++)--; //decrement the next digit. so 300 -> 320
     *function(nums, num, high, digit_total, digit_curr++) //recurse

     *if(num.at(digit_curr++) == 9)
          return; //arithmetic violation: can't have a (10) digit. 
     num.at(digit_curr++)++; //increment the next digit. so 300 -> 340
     *function(nums, num, high, digit_total, digit_curr++) //recurse

     return; //catchall base case. for worst case scenarios */
// main()
//      vector<int> nums;
//      cin << low
//      cin << high
//      function(nums, low, high, 1, log10(high)+1) //the last bits just calculating digits
//      print(nums) //trivial