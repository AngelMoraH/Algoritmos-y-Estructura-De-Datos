#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
};

template<typename TV, typename TE>
class Graph{
private:    
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:
    bool insertVertex(string id, TV vertex) = 0;   
    bool createEdge(string id1, string id2, TE w) = 0;     
    bool deleteVertex(string id) = 0;     
    bool deleteEdge(string id1, string id2) = 0;   
    TE &operator()(string id1, string id2)= 0;  
    float density() = 0;
    bool isDense(float threshold = 0.5) = 0;
    bool isConnected()= 0; //or StronglyConnected
    bool empty() = 0;
    void clear()= 0;  
      
    void display() = 0;
    void displayVertex(string id)= 0;
    TV findById(string id) = 0;
};

#endif