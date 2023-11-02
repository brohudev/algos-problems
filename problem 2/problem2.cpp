# include <iostream>
# include <string>
# include <limits>
using namespace std;
// 1. Base case: i >= j
// 2. Calculate the middle index
// 3. Call the function on the left half
// 4. Call the function on the right half
// 5. Find the current max by subtracting the min left from the max right
// 6. Return the max of the three values (left max diff, right max diff, and curr max diff)
int main (){
     int n;
     int min = numeric_limits<int>::max();
     int max = numeric_limits<int>::max();
     
     int temp;
     for (int i = 0; i<n; i++){
          cin >> n;
          
     }
     return 0;
}