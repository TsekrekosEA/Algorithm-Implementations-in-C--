#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

// Define the graph as an adjacency list
using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

bool visited[1000];
bool inStack[1000]; 

bool DFSCycleSearch(const Graph& graph, int node){

    visited[node] = true;
    inStack[node] = true;
        
    bool cycleFound = false;

    for (auto neighbor : graph.at(node)) { // node is the int representation of the current node
        
        std::cout << "Exploring Node " << neighbor.first << " With cost of: " << neighbor.second << std::endl;
        if (!visited[neighbor.first]) {
            // Set parent relationship
            
            std::cout << "Exploring Node " << neighbor.first << " With cost of: " << neighbor.second << std::endl;
            
            if(DFSCycleSearch(graph, neighbor.first)){
                cycleFound = true;
            }
        }

        else if(visited[neighbor.first] && inStack[neighbor.first]){
            std::cout<< "Cycle detected at node: " << neighbor.first << std::endl;
            cycleFound = true;
        }
    }
    inStack[node] = false;
    return cycleFound;
}

void FindAllCycles(const Graph& graph) { // Cycle through all nodes to detect all possible cycles

    for(auto node : graph){ // std::pair<int, std::vector<std::pair<int, int>>>

        if(!visited[node.first]){
            DFSCycleSearch(graph, node.first);
        }
    }
}

int main(){

    Graph graph; 
    // Graph is an unorded map which maps an int (represents a graph node)
    // to a vector which contains all nodes it leads to, represented by a
    // pair where the first value is the node of the graph and second the cost.
    graph[0] = {{1,3},{2,1}};
    graph[1] = {{4,5},{2,1}};
    graph[2] = {{3,2},{0,8}};
    graph[3] = {{4,3},{5,6}};
    graph[4] = {{5,2}};
    graph[5] = {};

    // Reset visited and inStack arrays
    for (int i = 0; i < 1000; i++) {
        visited[i] = false;
        inStack[i] = false;
    }
    FindAllCycles(graph);

    return 0;

}