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
    node(int n) : num(n) {}  // Constructor to initialize the 'num' field
};
class Graph{
    public:
        Graph(int v) : adjacencylist(v), numNodes(v) {
        for (int i = 0; i < v; ++i) {
            adjacencylist[i] = new node(i);
        }
    };
        void addedge(int, int); // add edge v -> w in graph at the end of adj list
        int countsatisfiablenode(); //main solver.
        vector<node*> adjacencylist; // core data structure.
    private:
        int numNodes; //number of vertices in the graph
        bool iscyclicutil(int , vector<bool>&, vector<bool>&, vector<bool>&);
        bool instack(int, stack<int>);
};
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
bool Graph::iscyclicutil(int v, vector<bool>& visited, vector<bool>& recstack, vector<bool>& incycle){
    //todo implement
    if(!visited[v]){
        visited[v] = true;
        recstack[v] = true;
        for (auto neighbour : adjacencylist[v]->neighbours){
            if(!visited[neighbour] && iscyclicutil(neighbour, visited, recstack, incycle)){
                incycle[v] = true;
                return true;
            }
            else if(recstack[neighbour]){
                incycle[v] = true;
                return true;
            }
        }
        recstack[v] = false;//remove v from recstack. 
    }
    return false;
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
            iscyclicutil(node->num, visited, recstack, incycle); 
        }
    }
    int count = 0;
    for(int i=0; i<incycle.size(); i++){
        if(!incycle[i]) //ith index of incycle returns false
            count++;
    }
    return count;
}
int main(){
    int n,m,v,w; cin >> n; cin >> m;
    Graph g = Graph(n);
    for(int i = 0; i < m; i++){ // input all the nodes
        cin >> v >> w;
        g.addedge(v,w);
    }
    cout << g.countsatisfiablenode(); // fetch the answer.
    // cout << g.adjacencylist.size();
    // g.print(); //just to see our code works.
    return 0;
}