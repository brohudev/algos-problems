#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// insert nodes into bst.
node* insert(node* root, int val) {
    if (!root) {
        return new node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// build the bst.
node* buildBSTFromString(const string& input) {
    istringstream iss(input);
    int val;
    node* root = nullptr;
    while (iss >> val) {
        root = insert(root, val);
    }
    return root;
}

node* lca(node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
 
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);
 
    return root;
}

int findDistanceToNode(node* root, int target) {
     if (!root) {
          return -1; // Node not found
     }

     if (root->val == target) {
          return 0; // Found the target node
     }

     int leftDistance = findDistanceToNode(root->left, target);
     int rightDistance = findDistanceToNode(root->right, target);

     if (leftDistance != -1) {
          return 1 + leftDistance;
     }

     if (rightDistance != -1) {
          return 1 + rightDistance;
     }

     return -1; // Node not found in the subtree
}

int main() {
    string input = "";
    getline(cin, input);
    // Build the BST from the input string
    node* root = buildBSTFromString(input);
     int n1 , n2;
     cin >> n1; cin >>n2;
    node* t = lca(root, n1, n2);
    int distance = findDistanceToNode(t, n1) + findDistanceToNode(t, n2);
    cout << distance << endl;
    return 0;
}
