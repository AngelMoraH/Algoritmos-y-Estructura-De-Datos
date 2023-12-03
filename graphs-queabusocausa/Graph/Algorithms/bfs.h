#include <iostream>
#include <unordered_map>
#include <queue>
#include "graph.h"
template<typename TV, typename TE>
void bfs(const std::unordered_map<std::string, Vertex<TV, TE>*>& vertexes, const std::string& startId, std::unordered_map<std::string, bool>& visited) {
    std::queue<std::string> queue;
    queue.push(startId);
    visited[startId] = true;

    while (!queue.empty()) {
        std::string id = queue.front();
        queue.pop();

        Vertex<TV, TE>* vertex = vertexes.at(id);
        for (auto edge : vertex->edges) {
            Vertex<TV, TE>* otherVertex = edge->vertexes[1];
            if (!visited[otherVertex->data]) {
                visited[otherVertex->data] = true;
                queue.push(otherVertex->data);
            }
        }
    }
}