#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
//? dunno if we need this or not:
static const int inf = INT_MAX; //define a big asf number.
struct node{
     int townID; //the id of the town
     vector<pair<int,int>> edgelist; //list of (townID, Dist) connected to this node
     bool hasStation; //is this node a station?

     node(int id) : townID(id), hasStation(false) {}
};
//a class to store the graph data structure
class graph { 
     private:
          void addEdge(int fromNode, int toNode, int dist);
          vector<int> dijkstra(int currNode, int threshold); //already has adj list.        
     public:
          graph(int);
          int numNodes;
          vector<node*> adjacencyList;
     //yoinked from the graphs powerpoint slide # 7
     // public:
     //      enum EdgeClass {unknown, treeEdge, backEdge, forwardEdge, crossEdge};
     //      int V; // # nodes
     //      int E; // # edges
     //      int clock; // for dfs
     //      bool directed;
     //      vector<vector<int>> edgelists; // adjacency list
     //      vector<bool> marked; //for dfs/bfs
     //      vector<int>parent; // for dfs/bfs
     //      vector<int> pre; //for dfs
     //      vector<int> post; //for dfs
     //      vector<int> tree_out_degree;
     //      vector<int> earliest_reach;
     //      graph(int n) : directed(false), V(n), clock(0), edgelists(n, vector<int>()),
     //                     marked(n, false), parent(n, -1), post(n, -1), 
     //                     tree_out_degree(n,0), earliest_reach(n, -1) {}//initialize all vars
};
graph::graph(int n){
     numNodes = n; //assign and initialize the adjacency list.
     for(int i = 0; i < numNodes; i++){
          node* temp = new node(i);
          adjacencyList.push_back(temp);
     }
}
/*   at iterator +fromNode, insert a pair (toNode, dist)
     assume input is always in order.
     creates a pair entry (toNode, dist) at the fromNode index
     in the edgelist of the town of fromNode index.
*/
void graph::addEdge(int fromNode, int toNode, int dist){
     adjacencyList.at(fromNode)->edgelist.push_back(make_pair(toNode,dist));
}
// Define a function dijkstra:
//     Input: source node (src), adjacency list of graph (adj), distance threshold (d)
//     Initialize a distance array (dist) of size n (number of nodes) with all values as INF
//     Set the distance to the source node as 0
//     Create a priority queue (pq) to store nodes and their distances
//     Add the source node to pq with a distance of 0
//     While pq is not empty:
//         Get the node (u) and its distance from pq
//         If the current distance is greater than the distance in dist for node u, continue
//         For each neighbor (v) and weight (w) of u:
//             If the sum of current distance and weight is within threshold d and less than the distance in dist for v:
//                 Update the distance for v in dist
//                 Add v to pq with its updated distance
//     Return the dist array
vector<int> dijkstra(int numNodes, int sourceNode, int threshold, vector<node*> adjacencyList){
     vector<int> dist(numNodes, INT_MAX);
     dist[sourceNode] = 0; //set the source node dist to 0
     adjacencyList;//here to prove i can access it within. required as per pseudo.
     priority_queue<pair<int,int>> pq;//todo: sort based on ascending distance
     pq.push(make_pair(sourceNode, 0));
     while (!pq.empty()){
          pair<int,int> temp = pq.top(); pq.pop(); //get the top and pop it from pq
          if(temp.second > dist[temp.first])
               continue; //? why tho?
          for(auto pair : adjacencyList.at(sourceNode)->edgelist){
               //for each neighbour pair of u in the graph:
               if(pair.second + dist[sourceNode] <= threshold && 
                  pair.second + dist[sourceNode] < dist[pair.first]){
                    dist[pair.first] = pair.second;
                    pq.push(pair); //todo: fix the issue of duplicate pushes?
               }
          }
     }
     return dist; 
}

int main(){
     int n, d, k, b, m;
     cin >> n; // towns
     cin >> d; // dist threshold
     cin >> k; //well connected
     cin >> b; // bus stations
     cin >> m; // roads
     graph g = graph(n); //create a graph of n initialized nodes.
     vector<int> stations; 
     string input, temp;
     getline(cin, input);
     stringstream ss(input);
     while(!ss.eof()){
          ss >> temp;
          stations.push_back(stoi(temp)); //input all the stations.
     }
     vector<node*> adjacencylist; //declare the data structure for the graph.
     vector<int> reachable_list; // # of reacahble towns at index-th node.
     for(auto station : stations){
          vector<int> distances = dijkstra(n,station, d, adjacencylist);//run dijsktra
          
     }
     return 0;
}
// pseudocode yoinked from tzkal's discord post.
// Main Function:
//*     Read the number of nodes (n), distance threshold (d), minimum bus stations (k), number of bus stations (b), and number of roads (m)
//*    Initialize a list of bus stations
//*     Read the bus stations into the list
//*    Initialize an adjacency list (adj) for the graph
//*    Read the edges (roads) into the adjacency list with their weights
//*     Initialize a list (reachable_count) to store the count of reachable towns for each town
//     For each bus station:
//         Get distances to all towns using dijkstra
//         For each town:
//             If the town is reachable within distance d:
//                 Increment the count for that town in reachable_count
//     Initialize a variable for well-connected towns
//     For each town:
//         If the town is reachable from at least k bus stations:
//             Increment the count of well-connected towns
//     Print the number of well-connected towns
