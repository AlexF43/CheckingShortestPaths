#include <iostream>
#include "graph.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph<int> G {3};
    G.addEdge(0, 1, 2);
    G.addEdge(1, 0, -1);
    G.addEdge(1, 2, 10);
    G.addEdge(2, 1, -5);
    isSubgraph(G,G);
    return 0;
}
