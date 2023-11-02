// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <fstream>
// #include <cmath>
// using namespace std;
// /*swap(i) in range of the numbers length - 2:
//      places the ith digit at i+1 and palces the i+1th digit at i
// */
// int numswap(int i, int number){
//      string strnum = to_string(number);
//      if(i<strnum.length()-1){ //if the swap digit is in bounds. 
//           char temp = strnum[i+1]; //store the i+1th digit in temp. 
//           strnum[i+1] = strnum[i]; //set i+1th to ith char
//           strnum[i] = temp; // set the ith to i+1th char
//      }
//      return stoi(strnum);//return the swapped number 
// }
// /*struct obj:
//      int k //taken from input
//      int swaps // set 0 by default, the counter to check k against. also pt b's answer.
//      int knum //set zero by default. is the biggest number found after k swaps. i.e pt a's ans. 
// */
// struct object{
//      int k;
//      int swaps;
//      int knum;
// };
// /*function(obj, number):
//      temp = 0, max = number //set the max to number. this way you only recurse if max changes (i.e max > number)
//      for i in range num.length - 2:
//           temp = swap(i)
//           if temp > max
//                max = temp
//      if max > number: //i.e if it changed we accept the swap. 
//           obj.swaps++
//           if obj.swaps == obj.k:
//                obj.knum = max //set the largest number after k swaps. pt a ans found. 
//           function(obj, max)//recurse on the max number until you hit the base case. 
//      return //base case. i.e when max == number. well if max is always bigger than the number, and it cant be smaller
//                the only case left when max isnt > number is max == number... which is the base return. 
// */
// void function(object& obj, int number){
//      int temp = 0, max = number; // set the max to number. you only recurse if max changes(i.e become larger. take scare of the base case)
//      for(int i = 0; i < floor(log10(number)); i++){ //do n-1 swaps for n digits...
//           temp = numswap(i, number);
//           if (temp > max)
//                max = temp;
//      }
//      if(max > number){ // i.e if max changed, then it is garunteed to be the highest number after a swap, we accept this swap.
//           obj.swaps++;
//           if (obj.swaps == obj.k)
//                obj.knum = max; //set the largest number after k swaps. pt a answer found. 
//           function(obj,max); //recurse on the max number until you hit base case
//      }
//      return; //base case is when max <number. or when the rest of the top finishes running. 
//                //we store answer in a struct so nothing to return here. 
// };
// /*
// main:
//      input:
//           number
//           k
//      create obj object and set object.k to k. all the others initiated to 0.
//      function(object, number)
//      print(object.knum \n obj.swaps) //pt a \\n pt b. 
// */
// int main(){
//      int k, number;
//      cin >> k; cin >> number;
//      object obj;
//      obj.k = k; obj.knum = 0; obj.swaps = 0;
//      function(obj, number);
//      cout << obj.knum <<"\n"<< obj.swaps;
//      return 0;
// }
#include <iostream>
#include <string>
using namespace std;

void swap(string &str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void find_largest_number(string &str, int k, long long &largest, long long &current, int &count) {
    if (k == 0) return;

    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (i != j) {
                swap(str, i, j);
                long long num = stoll(str);

                if (num > largest) {
                    largest = num;
                    current = num;
                    count++;
                    find_largest_number(str, k - 1, largest, current, count);
                } else {
                    find_largest_number(str, k - 1, largest, current, count);
                }

                swap(str, i, j);
            }
        }
    }
}

pair<long long, int> find_maximum_number(string M, int K) {
    long long largest = stoll(M);
    long long current = stoll(M);
    int count = 0;
    find_largest_number(M, K, largest, current, count);
    return make_pair(largest, count);
}

int main() {
    string M1 = "129845";
    int K1 = 3;
    auto result1 = find_maximum_number(M1, K1);
    cout << result1.first << endl;

    string M2 = "129814999";
    int K2 = 2;
    auto result2 = find_maximum_number(M2, K2);
    cout << result2.second << endl;

    return 0;
}
