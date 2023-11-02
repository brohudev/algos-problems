#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct Node { // Define a node structure for the min-heap
     int val, freq = 0;
     Node* left;
     Node* right;
     Node(int value, int frequ) : val(value), freq(frequ), left(nullptr), right(nullptr) {}
     Node() : val(0), freq(0), left(nullptr), right(nullptr) {}

     // Overload the comparison operator to make the priority queue min-heap
     bool operator>(const Node& other) const {
          // Compare based on frequency, making it a min-heap
          return val > other.val;
     }
};
string canDivideIntoConsecutiveNums(priority_queue<Node, vector<Node>, greater<Node>>& freqHeap, int& k){
     if(freqHeap.empty())
          return "true. heap empty";
     if(freqHeap.size() < k)
          return "false. heap smaller than k";
     stack<Node> temp;
     vector<Node> temparray(k);
     for(int i=0;i<k;i++){ //pull k elements 
          vector<Node>::iterator it = temparray.begin() + i;
          temparray.insert(it,freqHeap.top());
          cout<<"temparray at "<<i<<" holds: "<<temparray.at(k-1).val<<endl;
          cout<<"freqHeap top holds: "<<freqHeap.top().val<<endl;
          freqHeap.pop();
          if(i>0 && freqHeap.top().val > (temparray.front().val+1))//if at any pt the two nums are not consec
               return "false. two nums not consecutive found";
     }
     //subtract frequencies
     for(int i=1;i<k;i++){
          cout<<temparray.at(i).freq << "is the frequency of: "<<temparray.at(i).val<<endl;
          cout<<temparray.front().freq << "is the frequency of the front: "<<temparray.front().val<<endl;

          temparray.at(i).freq -= temparray.front().freq; //remove the freq of the front from the ith consec num
          cout<<temparray.at(i).freq << "is the frequency of: "<<temparray.at(i).val<<"after modification"<<endl;

          if(temparray.at(i).freq <0)
               return "false. frequency less than 0 found.";
     }
     temparray.front().freq = 0;
     //cleanup the 0 freq ones from temparray
     int i=k-1;
     while(i>=0){//cleanup the 0 freq nodes and add the rest back onto the heap.
          if(temparray.at(i).freq == 0){
               temparray.pop_back(); //remove the Node w 0 freq.
          } else {
               Node temp = temparray.back(); //save the node in a temp one.
               freqHeap.push(temp); //push the node back onto the stack for the next call 
               temparray.pop_back(); // remove this node with freq>0
          }
     }
     return canDivideIntoConsecutiveNums(freqHeap, k);
}

int main() {
     string input = "1 2 2 3";
     int k = 2;
     // getline(cin, input);
     istringstream iss(input);
     vector<int> nums;
     int num;
     while (iss >> num) {
          nums.push_back(num);
     }
     // Create a min-heap from the vector of integers
     priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
     priority_queue<Node, vector<Node>, greater<Node>> freqHeap;
     sort(nums.begin(),nums.end());
     stack<int> temp;
     while(!nums.empty()){
          int val = nums.back(); // put the value of the back in a var
          Node temp(val, 0); // create a struct for it
          temp.freq++;
          nums.pop_back();
          while(nums.back() == val){ // until you hit a number ~= val
               nums.pop_back();
               temp.freq++;
          }
          freqHeap.push(temp);\
     }

     cout << canDivideIntoConsecutiveNums(freqHeap, k) << endl;
     return 0;
}