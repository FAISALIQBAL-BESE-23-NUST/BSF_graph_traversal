#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to perform Breadth-First Search (BFS)
void bsf(vector<int> nodes, vector<vector<int>> edges, int startvalue)
{
    // Array to keep track of visited nodes, initialized to false
    bool visited[nodes.size()] = {false};
    queue<int> toVisit; // Queue to manage the order of node visits

    // This unordered map stores the mapping of node values to their respective indices
    unordered_map<int, int> nodeIndexMap;
    for (int i = 0; i < nodes.size(); i++) // Loop through all nodes
    {
        nodeIndexMap[nodes[i]] = i;
    }

    toVisit.push(startvalue); // Add the start node value to the queue
    // Mark the start node as visited using its index
    visited[nodeIndexMap[startvalue]] = true;

    // BFS traversal loop
    while (!toVisit.empty()) // Continue until all nodes are visited
    {
        int current = toVisit.front(); // Get the front node value in the queue

        toVisit.pop(); // Remove the front node from the queue

        cout << current << "-> "; // Print the current node value

        // Get the number of neighbors for the current node using its index
        int forlength = edges[nodeIndexMap[current]].size();

        // Iterate through all neighbors of the current node
        for (int i = 0; i < forlength; i++)
        {
            int nieghber = edges[nodeIndexMap[current]][i]; // Get the neighbor node value

            // Check if the neighbor has not been visited
            if (!visited[nodeIndexMap[nieghber]])
            {
                toVisit.push(nieghber); // Add the neighbor to the queue
                visited[nodeIndexMap[nieghber]] = true; // Mark the neighbor as visited
            }
        }
    }
}

int main()
{
    // Define the nodes in the graph
    vector<int> node = {1, 2, 3, 4, 5, 6, 7, 8};

// Define the adjacency list representing the graph edges

    vector<vector<int>> edges = {{2, 5},// Neighbors of node 1
    //and so on
     {6,1}, {4, 6, 7}, {3, 7, 8}, {1}, {2, 3, 7}, {3, 4, 6, 8}, {7, 4}};


    

    bsf(node, edges, 2); // Call the BFS function starting from node value 2

    return 0; // Exit the program
}
