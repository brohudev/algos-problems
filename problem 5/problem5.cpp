#include <iostream>
using namespace std;
 
// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Prints postorder traversal from given
// inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);
 
    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root);
 
    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
 
    // Print root
    cout << pre[0] << " ";
}
 
// Driver program to test above functions
int main()
{
    int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pre[] = { 2, 1, 5, 4, 3, 8, 7, 9, 6};
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    printPostOrder(in, pre, n);
    return 0;
}