#include <iostream>
#include <unordered_map>
#include <stack>
#include "graph.h"
using namespace std;

template<typename TV, typename TE>
void dfs(const unordered_map<std::string, Vertex<TV, TE>*>& vertexes, const std::string& startId, std::unordered_map<std::string, bool>& visited) {
    std::stack<std::string> stack;
    stack.push(startId);
    while (!stack.empty()) {
        std::string id = stack.top();
        stack.pop();
        visited[id] = true;
        Vertex<TV, TE>* vertex = vertexes.at(id);
        for (auto edge : vertex->edges) {
            Vertex<TV, TE>* otherVertex = edge->vertexes[1];
            if (!visited[otherVertex->data]) {
                stack.push(otherVertex->data);
            }
        }
    }
}