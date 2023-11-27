#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;
struct node{
    int num;
    vector<int> neighbours;// pairs of (node, distance) 
};
class Graph{
    public:
        Graph(int v) : adjacencylist(v), numNodes(v) {};
        void addedge(int, int); // add edge v -> w in graph at the end of adj list
        int countsatisfiablenode(); //main solver.
        vector<node*> adjacencylist; // core data structure.
        void print();
    private:
        int numNodes; //number of vertices in the graph
        bool isCyclicUtil(int , vector<bool>&, vector<bool>&, vector<bool>&);
        bool instack(int, stack<int>);
};
// Define a class Graph:
//     Properties:
//         V - number of vertices
//         adj - a list of adjacency lists for each vertex

//     Define a method addEdge:
//         Input: integers v and w (edge from v to w)
//         Add w to the adjacency list of the vth index in adj list
void Graph::addedge(int v, int w){
    adjacencylist[v]->neighbours.push_back(w);
}

//     Define a method isCyclicUtil (private):
//         Input: an integer v, arrays visited, recStack, and inCycle
//         If v is not visited:
//             Mark v as visited and part of the recursion stack (recStack)
//             For each adjacent vertex i of v:
//                 If i is not visited and isCyclicUtil for i returns true:
//                     Mark inCycle[v] as true
//                     Return true
//                 Else if i is in the recursion stack:
//                     Mark inCycle[v] as true
//                     Return true
//             Remove v from the recursion stack
//         Return false
bool Graph::isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recstack, vector<bool>& incycle){
    //todo implement
    if(!visited[v]){
        visited[v] = true;
        recstack[v] = true;
        for (auto neighbour : adjacencylist[v]->neighbours){
            if(!visited[neighbour] && isCyclicUtil(neighbour, visited, recstack, incycle)){
                incycle[v] = true;
                return true;
            }
            else if(recstack[v]){
                incycle[v] = true;
                return true;
            }
        }
        recstack[v] = false;//remove v from recstack. 
    }
    return false;
}

// implement instack emthod
bool Graph::instack(int v, stack<int> stack){
// Create a temporary stack to store elements as we search
    std::stack<int> tempStack = stack;
    // Iterate through the temporary stack to check for the target element
    while (!tempStack.empty()) {
        if (tempStack.top() == v) {
            return true; // Element found in the stack
        }
        tempStack.pop();
    }

    return false; // Element not found in the stack
}

//     Define a method countSatisfiableNodes:
//         Create arrays visited, recStack, and inCycle, all initialized with false values
//         For each vertex i from 0 to V - 1:
//             If i is not visited:
//                 Call isCyclicUtil for i
//         Initialize count to 0
//         For each vertex i from 0 to V - 1:
//             If inCycle[i] is false:
//                 Increment count
//         Return count
int Graph::countsatisfiablenode(){
    //todo implement 
    vector<bool> visited(numNodes, false), 
                 incycle(numNodes, false),
                 recstack(numNodes, false);
    for(auto node : adjacencylist){
        if(!visited[node->num]){
            isCyclicUtil(node->num, visited, recstack, incycle); 
        }
    }
    int count = 0;
    for(auto cyclicCell : incycle){
        if(!cyclicCell)
            count++;
    }
    return count;
}

//     Define a method printGraph (for debugging):
//         For each vertex v from 0 to V - 1:
//             Print the adjacency list of v
void Graph::print(){
    for (auto vertex : adjacencylist){ //for every node in the list
        cout << "node: "<<vertex->num << " has neighbours:-\n";
        for (auto neighbour : vertex->neighbours){ // for every neighbor of the edge list
            cout << neighbour <<";  ";
        }
        cout << "\n";
    }
}

int main(){
    int n,m,v,w; cin >> n; cin >> m;
    Graph g = Graph(n);
    for(int i = 0; i < m-1; i++){ // input all the nodes
        cin >> v; cin >> w;
        g.addedge(v,w);
    }
    // cout << g.countsatisfiablenode(); // fetch the answer.
    g.print(); //just to see our code works.
    return 0;
}
// Main Function:
//     Read integers n (number of vertices) and m (number of edges)
//     Create a Graph g with n vertices
//     For each edge from 0 to m - 1:
//         Read integers v and w (edge from v to w)
//         Add edge v to w in graph g
    // Output the result of calling countSatisfiableNodes on g
//     End program