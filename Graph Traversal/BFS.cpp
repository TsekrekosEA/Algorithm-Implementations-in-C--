#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

// Define the graph as an adjacency list
using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

bool visited[1000];
std::unordered_map<int, int> parent; // Parent map to reconstruct the path
std::queue<std::pair<int, int>> nodes;

void BFS(const Graph& graph, int startNode, int targetNode, bool& found){

    // Clear queue and reset visited
    while (!nodes.empty()) nodes.pop();
    for (int i = 0; i < 1000; i++) visited[i] = false;
    
    nodes.push({startNode, 0}); // node, cost
    visited[startNode] = true;

    while (!nodes.empty() && !found) {
        std::pair<int,int> node = nodes.front();
        nodes.pop();
        

        if (node.first == targetNode) {
            found = true;
            break;
        }

        for (auto& neighbor : graph.at(node.first)) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                parent[neighbor.first] = node.first;
                nodes.push(neighbor);
                std::cout << "Exploring Node " << neighbor.first << " With cost of: " << neighbor.second << std::endl;
            }
        }

    }
}

std::vector<int> reconstructPath(int startNode, int targetNode) {
    std::vector<int> path;
    
    // If target wasn't reached, return empty path
    if (!visited[targetNode]) {
        return path;
    }
    
    // Reconstruct path by following parents backward from target
    for (int i = targetNode; i != -1; i = parent[i]) {
        path.push_back(i);
    }

    // Reverse to get path from start to target
    std::reverse(path.begin(), path.end());
    return path;
}

int main(){

    Graph graph; 
    // Graph is an unorded map which maps an int (represents a graph node)
    // to a vector which contains all nodes it leads to, represented by a
    // pair where the first value is the node of the graph and second the cost.
    graph[0] = {{1,3},{2,2}};
    graph[1] = {{4,5}};
    graph[2] = {{3,2}};
    graph[3] = {{4,3},{5,7}};
    graph[4] = {{5,2}};
    graph[5] = {};


    int startNode = 0;
    int targetNode = 5;
    bool found = false;


    // Clear parent map
    parent.clear();
    parent[startNode] = -1;

    BFS(graph,startNode,targetNode,found);

    std::vector<int> path = reconstructPath(startNode, targetNode);
    
    std::cout << "Path from " << startNode << " to " << targetNode << ": ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;

}