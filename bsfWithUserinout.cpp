#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map> // For the unordered_map to map node values to indices

using namespace std;

// Function to perform Breadth-First Search (BFS)
void bsf(vector<int> nodes, vector<vector<int>> edges,unordered_map<int, int> nodeIndexMap, int startvalue)
{
    // Array to keep track of visited nodes, initialized to false
    bool visited[nodes.size()] = {false};
    queue<int> toVisit; // Queue to manage the order of node visits

   
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
                toVisit.push(nieghber);                 // Add the neighbor to the queue
                visited[nodeIndexMap[nieghber]] = true; // Mark the neighbor as visited
            }
        }
    }
}

int main()
{
    int N, E; // Number of nodes and edges
    cout << "Enter the number of nodes (N): ";
    cin >> N;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<int> nodes(N); // Vector to store node values
    cout << "Enter the node values: ";
    for (int i = 0; i < N; i++)
    
    {
        cout<<"Node-> "<<i+1<<" : ";
        cin >> nodes[i]; // Input node values
    }

 // This unordered map stores the mapping of node values to their respective indices
    unordered_map<int, int> nodeIndexMap;
    for (int i = 0; i < nodes.size(); i++) // Loop through all nodes
    {
        nodeIndexMap[nodes[i]] = i; // Map node value to its index in the nodes vector
    }

    vector<vector<int>> edges(N); // Adjacency list to represent the graph
     cout << "Enter the edges (u v):\n";
     for (int i = 0; i < E; i++)
    {
        cout<<"edge-> "<<i+1<<" : ";
        int u, v;
        cin >> u >> v; // Input an edge between u and v

    edges[nodeIndexMap[u]].push_back(v);
    edges[nodeIndexMap[v]].push_back(u);

    }


    int startvalue; // Starting node for BFS
    cout << "Enter the starting node value: ";
    cin >> startvalue;


        bsf(nodes, edges,nodeIndexMap, startvalue); // Call the BFS function starting from node value 2

        return 0; // Exit the program
    }
