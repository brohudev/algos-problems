def search(arr, x, n):
      
    for i in range(n):
        if (arr[i] == x):
            return i
 
    return -1

def printPostOrder(In, pre, n):
     
    # The first element in pre[] is always
    # root, search it in in[] to find left
    # and right subtrees
    root = search(In, pre[0], n)
 
    # If left subtree is not empty,
    # print left subtree
    if (root != 0):
        printPostOrder(In, pre[1:n], root)
 
    # If right subtree is not empty,
    # print right subtree
    if (root != n - 1):
        printPostOrder(In[root + 1 : n],
                      pre[root + 1 : n],
                      n - root - 1)
 
    # Print root
    print(pre[0], end = " ")
 
# Driver code
n = int(input())
pre = list(map(int, input().split()))
In = list(map(int, input().split())) 
printPostOrder(In, pre, n)