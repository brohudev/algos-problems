#include <iostream>
#include <string>
#include <climits>
using namespace std;
struct Node {
	int val;
	struct Node *left, *right;
	Node(int v)
	{
		val = v;
		left = right = nullptr;
	}
     Node()
     {
          val = INT_MIN;
          left = right = nullptr;
     }
};
void print(struct Node* node){
	if (node == NULL)
		return;

	// recurse on the left subtree
	print(node->left);

	// print the node
	cout << node->val << " ";

	//recurse on the right subtree
	print(node->right);
}
void deserialize(Node* ptr, string serial){
     //if the string is empty do nothing.
     if(serial.empty())
          return;
     //if the current character is '}' then return after removing it. 
     if(serial[0] == '}'){
          serial = serial.substr(2);
          return;
     }
     //if the current character is '{' then recursively call on the function after removing this part. 
     else if(serial[0] == '{'){
          serial = serial.substr(1);
          deserialize(ptr->left, serial);
          return;
     }
     //if the character is { for a second time then go to the right branch. 
     else if(serial[0] == '{'){
          serial = serial.substr(1);
          deserialize(ptr->right, serial);
          return;
     }
     else{  //if the current character is a number, enter the number to ptr
          ptr->val = stoi(serial.substr(0,serial.find_first_of(' '))); //set the value.
          serial = serial.substr(serial.find_first_of(' ')+1);//remove the value. 
          deserialize(ptr, serial);
     }
     return;
}
int main(){
	struct Node* root = new Node();
     string input; getline(cin, input);
     deserialize(root, input);// Function call
	print(root); //print the results.
	return 0;
}