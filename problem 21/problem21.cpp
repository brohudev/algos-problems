#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool notfound(vector<int>& mappings, int value){
     for(auto mapping : mappings){
          if(mapping == value){
               return false; // you found a match. no bueno
          }
     }  
     return true;
}
bool isvalid(vector<int>& mappings, string& str1, string& str2, string& str3){
     int carry = 0;
     int str1digit, str2digit, str3digit;
     for(int i = 0; i < str3.length(); i++){
          if(str3.length() > str1.length() && i >= str1.length())//case when carry leads to an extra digit in str3...
               str1digit =0, str2digit=0, str3digit=mappings[int(str3[i]-65)];
          else{
               str1digit = mappings[int(str1[i])-65];
               str2digit = mappings[int(str2[i])-65];
               str3digit = mappings[int(str3[i])-65];
          }
          if(((str1digit + str2digit + carry)%10) != str3digit)// if any digit sum is not valid, accounting for carries,
               return false;
          carry = floor((str1digit+str2digit)/10); // set the carry bit to 1 if sum >10, 0 otherwise. 
     }
     return true; 
}
/*
bool notFound(mappings[], int value):
     for mapping in mappings:
          if mapping == value:
               return False   //*returns false if the value IS INDEED found in mappings
     return False //*the value is good to go.

bool isValid(mappings, str1, tr2, str3):
     int carry = 0
     for i in range str3.length:
          grab the digit assignments for letters at i in str1 and str2
          if theres one more digit in str3, then set str2 and str1's digits to 0 //*this takes care of carry overflow. 
          if (digit1 + digit2 + carry) %10 != digit3:
               return false //*the assignment is invalid.
          carry = floor((digit1 + digit2)/10) //*or do a simple boolean check. wtvr works tbh. 
     return true; 

bool backtrack(int symbolindex, mappings[], string str1, string str2, string str3, string symbollist)
     if(symbolindex is at symbollist's end)
          reutrn isValid(mappings, str1, str2, str3) //*base case check if all mappings are correct
     for every digit at the index of symbollist:
          if(notFound(mappings, i)):
               mappings[symbolindex] = digit //*set that digit to that symbol cuz it hasn't been asigned yet.
               if(backtrack(symbolindex++, mappings, str1, str2, str3, symbollist)) //*if you found the correct one return it
                    return True
               else
                    mappings[symbolindex] = -1 //*reset the mappings. 
     return false; //*catchall for oopsies; also the function requires a return to avoid seg faults and race conditions

main:
     input >> symbollist
     input >> str1
     input >> str2
     input >> str3
     reverse str1 to 3
     initailize mappings[]
     if(backtracking(0, mappings[], str1, str2, str3, symbollist))
          for mapping in mappins:
               print mapping
          return 0;
     cout no valid mapping found
     return 0;
*/
bool backtrack(int symbolindex, vector<int>& mappings, string& symbollist, string& str1, string& str2, string& str3){
     if(symbolindex >= symbollist.length())
          return isvalid(mappings, str1, str2, str3);
     for(int i =0; i< 10; i++){
          if(notfound(mappings, i)){//the digit hasnt been assigned yet...
               mappings[symbolindex] = i;//set the current symbol to i 
               if(backtrack(symbolindex+1, mappings, symbollist, str1, str2, str3)){ // if you found a backtrack 
                    return true;
               }//else continue the loop...
          }
     }
     return false; // catchall for edge cases :skull
}
int main(){
     string symbollist, str1, str2, str3; 
     cin >> symbollist; cin >> str1; cin >> str2; cin >> str3; 
     // reverse all the strings so backtracking works iteratively from left to right.
     reverse(str1.begin(), str1.end()); reverse(str2.begin(), str2.end()); reverse(str3.begin(), str3.end());  
     vector<int> mappings, used_digits;
     for(int i = 0; i < symbollist.length(); i++){
          mappings.push_back(-1);// add -1s to mapping so line 61 works as expected
     }
     // start backtracking from 0
     if (backtrack(0, mappings, symbollist, str1, str2, str3)){//if backtracking was successful
          for(auto num : mappings){
               cout << num; // print the mappings out in order. 
          }
          return 0;
     }
     cout << "no valid mapping found";
     return 0;
}
