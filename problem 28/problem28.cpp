// function maxElephantWeights(n, m, edges):
//     graph = initializeGraph(n, edges)  // Initialize the graph with edge weights
//     // Create an array to store the maximum weight of elephant that can reach each island
//     maxWeights = array of size n
//     maxWeights[0] = 0  // The starting island has weight 0
//     // Create a priority queue to process the islands based on maximum elephant weight
//     priorityQueue = PriorityQueue()
//     // Enqueue the starting island with weight 0
//     priorityQueue.enqueue(0, 0)
//     // Process the islands
//     while priorityQueue is not empty:
//         currentIsland, currentWeight = priorityQueue.dequeue()
//         // Iterate through neighbors of the current island
//         for neighbor, edgeWeight in graph[currentIsland]:
//             // Update the maximum weight of elephant that can reach the neighbor island
//             updatedWeight = min(currentWeight, edgeWeight)
//             if updatedWeight > maxWeights[neighbor]:
//                 maxWeights[neighbor] = updatedWeight
//                 priorityQueue.enqueue(neighbor, updatedWeight)
//     // Print the result for each island excluding the first island
//     for i from 1 to n-1:
//         print(maxWeights[i], end=" ")
// // Helper function to initialize the graph from the list of edges
// function initializeGraph(n, edges):
//     graph = array of size n, where each element is an empty list
//     for edge in edges:
//         src, dst, weight = edge
//         graph[src].append((dst, weight))
//         graph[dst].append((src, weight))  // Since the graph is undirected
//     return graph
// // Priority Queue implementation for Dijkstra's algorithm
// class PriorityQueue:
//     // Implementation of priority queue operations (enqueue and dequeue) using a min heap
//     // You can use a built-in priority queue in some programming languages
