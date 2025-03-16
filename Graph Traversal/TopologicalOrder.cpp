#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <stack>

// Define the graph as an adjacency list
using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

bool visited[1000];


std::stack<int> Topologicalorder; // stack to store topological order

void DFS(const Graph& graph, int startNode){

    visited[startNode] = true;


    for (auto neighbor : graph.at(startNode)) {
        if (!visited[neighbor.first]) {
            
            std::cout << "Exploring Node " << neighbor.first << " With cost of: " << neighbor.second << std::endl;
            
            DFS(graph, neighbor.first);
            
        }
    }
    Topologicalorder.push(startNode);
}

void ItterateGraphNodes(const Graph& graph) { // Cycle through all nodes for Topological Order

    for(auto node : graph){ // std::pair<int, std::vector<std::pair<int, int>>>

        if(!visited[node.first]){
            DFS(graph, node.first);
        }
    }
}



int main(){

    Graph graph; 
    // Graph is an unorded map which maps an int (represents a graph node)
    // to a vector which contains all nodes it leads to, represented by a
    // pair where the first value is the node of the graph and second the cost.
    graph[0] = {{1,3},{2,2}};
    graph[1] = {{4,5}};
    graph[2] = {{3,2}};
    graph[3] = {{4,3},{5,6}};
    graph[4] = {{5,2}};
    graph[5] = {};


    int startNode = 0;
    int targetNode = 5;
    bool found = false;

    // Reset visited array
    for (int i = 0; i < 1000; i++) {
        visited[i] = false;
    }
    // Clear stack
    while (!Topologicalorder.empty()){
        Topologicalorder.pop();
    }

    ItterateGraphNodes(graph);

    while (!Topologicalorder.empty()){
        std::cout << Topologicalorder.top() << " , ";
        Topologicalorder.pop();
    }
    std::cout << std::endl;
    
    return 0;

}