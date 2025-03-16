#include <iostream>
#include <unordered_map>
#include <vector>

using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

void ItterateGraphNodes(const Graph& graph, int startNode){

    for (auto i : graph){
        std::cout << "Node " << i.first << " Connects to : ";
        for (auto j : i.second){
            std::cout << " Node " << j.first << " with a cost of : " << j.second << ",";
        }
        std::cout << std::endl;
    }
}


void BestNode(const Graph& graph, int startNode){

    std::pair<int, int> bestNode = {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};

    for (auto neighbor : graph.at(startNode)){
        std::cout << "Neighbor: " << neighbor.first << ", Cost: " << neighbor.second << std::endl;
        if(neighbor.second < bestNode.second){ 
            bestNode=neighbor;
        }
    }
    std::cout << "BestNeighbor: " << bestNode.first << ", Cost: " << bestNode.second << std::endl;

}
