#include <iostream>
#include "graph.hpp"

int main() {
    Graph<int> G {7};
    G.addEdge(0, 1, 2);
    G.addEdge(0, 2, -1);
    G.addEdge(1, 3, 1);
    G.addEdge(1, 4, 5);
    G.addEdge(2, 5, 3);
    G.addEdge(2, 6, 2);
//    std::vector<int> distances {0, 2, -1, 3, 7, 2, 1};
    std::vector<int> distances {pathLengthsFromRoot(G, 0)};
    for (auto distance : distances) {
        std::cout<<distance;
    }
    return 0;
}
