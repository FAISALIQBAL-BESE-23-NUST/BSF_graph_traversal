#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void bsf(vector<int> nodes, vector<vector<int>> edges, int startvalue)
{
    bool visited[nodes.size()] = {false};
    queue<int> toVisit;

    // This will store the index corresponding to the node value in the nodes vector
    unordered_map<int, int> nodeIndexMap;
    for (int i = 0; i < nodes.size(); i++)
    {
        nodeIndexMap[nodes[i]] = i;
    }

    toVisit.push(startvalue);
    // Mark the start node as visited
    visited[nodeIndexMap[startvalue]] = true;

    while (!toVisit.empty())
    {
        int current = toVisit.front();  // Get the current node value
        toVisit.pop();

        cout << current << "-> ";  // Print the current node value

        int forlength = edges[nodeIndexMap[current]].size();  // Get number of neighbors

        // Iterate through neighbors of the current node
        for (int i = 0; i < forlength; i++)
        {
            int neighbor = edges[nodeIndexMap[current]][i];

            // If the neighbor has not been visited
            if (!visited[nodeIndexMap[neighbor]])
            {
                toVisit.push(neighbor);  // Add neighbor to queue
                visited[nodeIndexMap[neighbor]] = true;  // Mark neighbor as visited
            }
        }
    }
}

int main()
{
    
    vector<int> node = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<int>> edges = {{2, 5}, {6,1}, {4, 6, 7}, {3, 7, 8}, {1}, {2, 3, 7}, {3, 4, 6, 8}, {7, 4}};


    bsf(node, edges, 2);  // Starting BFS from node value 2
    return 0;
}
