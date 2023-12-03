#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"
#include "Algorithms/dfs.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
public:
    bool insertVertex(string id, TV vertex) {
        if (this->vertexes.find(id) != this->vertexes.end()) {
            return false;
        }
        
        Vertex<TV, TE>* newVertex = new Vertex<TV, TE>;
        newVertex->data = vertex;
        
        this->vertexes[id] = newVertex;
        return true;
    }
    
    bool createEdge(string id1, string id2, TE w) {
        if (this->vertexes.find(id1) == this->vertexes.end() || this->vertexes.find(id2) == this->vertexes.end()) {
            return false;
        }
        
        Vertex<TV, TE>* vertex1 = this->vertexes[id1];
        Vertex<TV, TE>* vertex2 = this->vertexes[id2];
        
        Edge<TV, TE>* newEdge = new Edge<TV, TE>;
        newEdge->vertexes[0] = vertex1;
        newEdge->vertexes[1] = vertex2;
        newEdge->weight = w;
        
        vertex1->edges.push_back(newEdge);
        vertex2->edges.push_back(newEdge);
        
        return true;
    }
    
    bool deleteVertex(string id) {
        if (this->vertexes.find(id) == this->vertexes.end()) {
            return false;
        }
        
        Vertex<TV, TE>* vertexToDelete = this->vertexes[id];
        
        for (auto edge : vertexToDelete->edges) {
            Vertex<TV, TE>* otherVertex = (edge->vertexes[0] == vertexToDelete) ? edge->vertexes[1] : edge->vertexes[0];
            otherVertex->edges.remove(edge);
            delete edge;
        }
        
        this->vertexes.erase(id);
        delete vertexToDelete;
        
        return true;
    }
    
    bool deleteEdge(string id1, string id2) {
        if (this->vertexes.find(id1) == this->vertexes.end() || this->vertexes.find(id2) == this->vertexes.end()) {
            return false;
        }
        
        Vertex<TV, TE>* vertex1 = this->vertexes[id1];
        Vertex<TV, TE>* vertex2 = this->vertexes[id2];
        
        Edge<TV, TE>* edgeToDelete = nullptr;
        
        for (auto edge : vertex1->edges) {
            if ((edge->vertexes[0] == vertex1 && edge->vertexes[1] == vertex2) ||
                (edge->vertexes[0] == vertex2 && edge->vertexes[1] == vertex1)) {
                edgeToDelete = edge;
                break;
            }
        }
        
        if (edgeToDelete == nullptr) {
            return false;
        }
        
        vertex1->edges.remove(edgeToDelete);
        vertex2->edges.remove(edgeToDelete);
        delete edgeToDelete;
        
        return true;
    }
    
    TE& operator()(string id1, string id2) {
        static TE nullWeight;
        
        if (this->vertexes.find(id1) == this->vertexes.end() || this->vertexes.find(id2) == this->vertexes.end()) {
            return nullWeight;
        }
        
        Vertex<TV, TE>* vertex1 = this->vertexes[id1];
        Vertex<TV, TE>* vertex2 = this->vertexes[id2];
        
        for (auto edge : vertex1->edges) {
            if ((edge->vertexes[0] == vertex1 && edge->vertexes[1] == vertex2) ||
                (edge->vertexes[0] == vertex2 && edge->vertexes[1] == vertex1)) {
                return edge->weight;
            }
        }
        return nullWeight;
    }
    
    float density() {
        int numVertices = this->vertexes.size();
        int numEdges = 0;
        
        for (const auto& vertexPair : this->vertexes) {
            numEdges += vertexPair.second->edges.size();
        }
        
        if (numVertices == 0) {
            return 0.0f;
        }
        
        return static_cast<float>(numEdges) / (numVertices * (numVertices - 1));
    }
    
    bool isDense(float threshold = 0.5) {
        return density() >= threshold;
    }
    
    bool isConnected() {
        if (this->vertexes.empty()) {
            return false;
        }
        
        string startId = this->vertexes.begin()->first;
        unordered_map<string, bool> visited;
        
        dfs(startId, visited);
        for (const auto& vertexPair : this->vertexes) {
            if (!visited[vertexPair.first]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool empty() {
        return this->vertexes.empty();
    }
    
    void clear() {
        for (auto& vertexPair : this->vertexes) {
            Vertex<TV, TE>* vertex = vertexPair.second;
            
            for (auto edge : vertex->edges) {
                delete edge;
            }
            
            delete vertex;
        }
        
        this->vertexes.clear();
    }
    
    void display() {
        for (const auto& vertexPair : this->vertexes) {
            cout << vertexPair.first << " -> ";
            
            const Vertex<TV, TE>* vertex = vertexPair.second;
            
            for (auto edge : vertex->edges) {
                Vertex<TV, TE>* otherVertex = (edge->vertexes[0] == vertex) ? edge->vertexes[1] : edge->vertexes[0];
                cout << otherVertex->data << "(" << edge->weight << ") ";
            }
            
            cout << endl;
        }
    }
    
    void displayVertex(string id) {
        if (this->vertexes.find(id) == this->vertexes.end()) {
            cout << "Vertex not found" << endl;
            return;
        }
        
        cout << id << " -> ";
        
        const Vertex<TV, TE>* vertex = this->vertexes[id];
        
        for (auto edge : vertex->edges) {
            Vertex<TV, TE>* otherVertex = (edge->vertexes[0] == vertex) ? edge->vertexes[1] : edge->vertexes[0];
            cout << otherVertex->data << "(" << edge->weight << ") ";
        }
        
        cout << endl;
    }
    
    TV findById(string id) {
        if (this->vertexes.find(id) != this->vertexes.end()) {
            return this->vertexes[id]->data;
        }
        
        return TV();
    }
};

#endif