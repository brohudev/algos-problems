/*
Define a class Graph:
    Properties:
        V - number of vertices
        adj - a list of adjacency lists for each vertex

    Define a constructor for Graph:
        Input: an integer V (number of vertices)
        Set V to the provided value
        Initialize adj as a list of lists for V vertices

    Define a method addEdge:
        Input: integers v and w (edge from v to w)
        Add w to the adjacency list of v

    Define a method isCyclicUtil (private):
        Input: an integer v, arrays visited, recStack, and inCycle
        If v is not visited:
            Mark v as visited and part of the recursion stack (recStack)
            For each adjacent vertex i of v:
                If i is not visited and isCyclicUtil for i returns true:
                    Mark inCycle[v] as true
                    Return true
                Else if i is in the recursion stack:
                    Mark inCycle[v] as true
                    Return true
            Remove v from the recursion stack
        Return false

    Define a method countSatisfiableNodes:
        Create arrays visited, recStack, and inCycle, all initialized with false values
        For each vertex i from 0 to V - 1:
            If i is not visited:
                Call isCyclicUtil for i
        Initialize count to 0
        For each vertex i from 0 to V - 1:
            If inCycle[i] is false:
                Increment count
        Return count

    Define a method printGraph (for debugging):
        For each vertex v from 0 to V - 1:
            Print the adjacency list of v

Main Function:
    Read integers n (number of vertices) and m (number of edges)
    Create a Graph g with n vertices
    For each edge from 0 to m - 1:
        Read integers v and w (edge from v to w)
        Add edge v to w in graph g
    Output the result of calling countSatisfiableNodes on g
    End program
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
class Graph{
    public:
        Graph(int);
        void addedge(int, int); // add edge v -> w in graph at the end of adj list
        int countsatisfiablenode(); //main solver.
    private:
        void putmethodhere();

};

int main(){
    int n,m,v,w; cin >> n; cin >> m;
    Graph g = Graph(n);
    for(int i = 0; i < m-1; i++){ // input all the nodes
        cin >> v; cin >> w;
        g.addedge(v,w);
    }
    cout << g.countsatisfiablenode(); // fetch the answer.
    return 0;
}