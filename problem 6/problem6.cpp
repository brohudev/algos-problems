#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
dfs(n, i, j, matrix)
     if(matrix(i)(j) == 1 and visited(i)(j)=F and i,j are in range[0,n))
          set matrix[i][j] to -1, signifying its been visited
          left = max(0,j-1); dfs (n,i,left, matrix)
          right = min(n,j+1); dfs (n,i,right, matrix)
          down = max(0,i-1); dfs (n,down,j, matrix)
          up = min(n,i+1); dfs (n,up,j, matrix)
     return
*/
void dfs(int& n, int i, int j,  vector<vector<int>>& matrix){
     if(i >= 0 && i < n && j >= 0 && j < n) //if in bounds.
          if(matrix[i][j] == 1){
               matrix[i][j] = -1;
               int left = max(0,j-1);  dfs(n , i, left, matrix); //recursively mark all the points in the island.
               int right = min(n,j+1); dfs(n , i, right, matrix);
               int down = max(0,i-1);  dfs(n , down, j, matrix);
               int up = min(n,i+1);    dfs(n , up, j, matrix);
          }
     return; //here just in case
}
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
     vector<vector<int>> matrix(n, vector<int>(n));//create a matrix of size n.
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               cin >> matrix[i][j]; //input all the values
          }
     }
     for(int i=0; i<matrix.size(); i++){ //in i rows
          for(int j=0; j < matrix[0].size(); j++){ //in j columns
               if(matrix[i][j] == 1){ //we use -1 to signify visited, 0 for water, 1 for land. 
                    //i.e if the cell is land and is not visited. 
                    dfs(n, i, j, matrix); //run dfs on the new found island.
                    islands++; //increment counter.
               }
          }
     }
     cout << islands; //print answer.
     return 0;
}