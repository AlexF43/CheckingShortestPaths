//
// Created by Alex Fogg on 22/5/2024.
//

#ifndef CHECKINGSHORTESTPATH_GRAPH_HPP
#define CHECKINGSHORTESTPATH_GRAPH_HPP

#include <iostream>
#include <fstream>
#include <utility>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <limits>
#include <stdexcept>

template <typename T>
class Graph {
private:
    std::vector<std::unordered_map<int, T> > adjList {};
    int numVertices {};

public:
    // empty graph with N vertices
    explicit Graph(int N);

    // construct graph from edge list in filename
    explicit Graph(const std::string& filename);

    // add an edge directed from vertex i to vertex j with given weight
    void addEdge(int i, int j, T weight);

    // removes edge from vertex i to vertex j
    void removeEdge(int i, int j);

    // is there an edge from vertex i to vertex j?
    bool isEdge(int i, int j) const;

    // return weight of edge from i to j
    // will throw an exception if there is no edge from i to j
    T getEdgeWeight(int i, int j) const;

    // returns number of vertices in the graph
    int size() const;

    // alias a const iterator to our adjacency list type to iterator
    using iterator =
            typename std::vector<std::unordered_map<int, T> >::const_iterator;

    // cbegin returns const iterator pointing to first element of adjList
    iterator begin() const {
        return adjList.cbegin();
    }

    iterator end() const {
        return adjList.cend();
    }

    // return iterator to a particular vertex
    iterator neighbours(int a) const {
        return adjList.begin() + a;
    }
};

template <typename T>
Graph<T>::Graph(int N) : adjList(N), numVertices {N} {}

template <typename T>
Graph<T>::Graph(const std::string& inputFile) {
    std::ifstream infile {inputFile};
    if (!infile) {
        std::cerr << inputFile << " could not be opened\n";
        return;
    }
    // first line has number of vertices
    infile >> numVertices;
    adjList.resize(numVertices);
    int i {};
    int j {};
    double weight {};
    // assume each remaining line is of form
    // origin dest weight
    while (infile >> i >> j >> weight) {
        addEdge(i, j, static_cast<T>(weight));
    }
}

template <typename T>
int Graph<T>::size() const {
    return numVertices;
}

template <typename T>
void Graph<T>::addEdge(int i, int j, T weight) {
    if (i < 0 or i >= numVertices or j < 0 or j >= numVertices) {
        throw std::out_of_range("invalid vertex number");
    }
    adjList[i].insert({j, weight});
}

template <typename T>
void Graph<T>::removeEdge(int i, int j) {
    // check if i and j are valid
    if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
        adjList[i].erase(j);
    }
}

template <typename T>
bool Graph<T>::isEdge(int i, int j) const {
    if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
        return adjList.at(i).contains(j);
    }
    return false;
}

template <typename T>
T Graph<T>::getEdgeWeight(int i, int j) const {
    return adjList.at(i).at(j);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Graph<T>& G) {
    for (int i = 0; i < G.size(); ++i) {
        out << i << ':';
        for (const auto& [neighbour, weight] : *(G.neighbours(i))) {
            out << " (" << i << ", " << neighbour << ")[" << weight << ']';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
bool isSubgraph(const Graph<T>& H, const Graph<T>& G) {
    if (H.size() > G.size()) {
        return false;
    }

    for(int edgeIndex = 0; edgeIndex < H.size(); edgeIndex++) {
        for (const auto& [neighbour, weight] : *(H.neighbours(edgeIndex))) {
            if (!G.isEdge(edgeIndex, neighbour) || G.getEdgeWeight(edgeIndex, neighbour) != weight) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool isTreePlusIsolated(const Graph<T>& G, int root) {
    return true;
}

template <typename T>
std::vector<T> pathLengthsFromRoot(const Graph<T>& tree, int root) {
    std::vector<T> bestDistanceTo(tree.size());
    return bestDistanceTo;
}

template <typename T>
bool allEdgesRelaxed(const std::vector<T>& bestDistanceTo, const Graph<T>& G,
                     int source) {
    return true;
}

#endif //CHECKINGSHORTESTPATH_GRAPH_HPP
