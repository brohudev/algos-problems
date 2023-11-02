#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

/*
dfs(n, i, j, matrix, , visited)
     if(matrix(i)(j) == 1 and visited(i)(j)=F and i,j are in range[0,n))
          set visited[i][j] to true
          left = max(0,j-1); dfs (n,i,left, matrix, visited)
          right = min(n,j+1); dfs (n,i,right, matrix, visited)
          down = max(0,i-1); dfs (n,down,j, matrix, visited)
          up = min(n,i+1); dfs (n,up,j, matrix, visited)
     return
*/
/*
main()
     input values:
          n
          the matrix into matrix[n][n]
          visited[n][n] set to all false. 
          islands = 0
     for every cell in the matrix:
          if(matrix(cell)==1 and !visited(cell))
               dfs(n, cell, matrix, visited)
*/
int main(){
     int n, islands = 0;
     cin >> n;
     string input = "";
     vector<vector<bool>> visited(n, vector<bool>(n));
     vector<vector<int>> matrix(n, vector<int>(n));//create a matrix of size n. 
     for(auto row : visited){//set each cell to false. 
          for(auto cell : row){   cell = false;   }
     }
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               cin >> matrix[i][j]; //input all the values
          }
     }
     
     return 0;
}