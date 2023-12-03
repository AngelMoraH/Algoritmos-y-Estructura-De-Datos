#include <iostream>
#include <vector>
#include <algorithm>
#include "ds.h"

using namespace std;

struct Edge
{
    char init;
    char end;
    int weight;
    Edge(char i, char e, int w = 0){ init = i; end = e; weight = w;}
};


/*struct Edge {
    char src;
    char dest;
    int weight;

    Edge(char s, char d, int w) : src(s), dest(d), weight(w) {}
};*/


/*
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<Edge> kruskal(vector<char>& vertices, vector<Edge>& edges) {
    vector<Edge> result;
    vector<char> parent;

    // Inicializar los conjuntos disjuntos
    for (char vertex : vertices) {
        parent.push_back(vertex);
    }

    // Ordenar las aristas en orden ascendente por su peso
    sort(edges.begin(), edges.end(), compareEdges);

    // Aplicar el algoritmo de Kruskal
    for (const Edge& edge : edges) {
        char srcParent = edge.init;
        char destParent = edge.end;

        // Buscar el padre de los vértices en el conjunto disjunto
        while (srcParent != parent[srcParent - 'A']) {
            srcParent = parent[srcParent - 'A'];
        }
        while (destParent != parent[destParent - 'A']) {
            destParent = parent[destParent - 'A'];
        }

        if (srcParent != destParent) {
            result.push_back(edge);

            // Unir los conjuntos
            parent[destParent - 'A'] = srcParent;
        }
    }

    return result;
}

void mostrar_ordenado(vector<Edge>& result) {
    for (const Edge& edge : result) {
        cout << edge.init << " - " << edge.end << " : " << edge.weight << endl;
    }
}*/


vector<Edge> kruskal(vector<char> vertices, vector<Edge> aristas){
    vector<Edge> solucion;
    DisjoinSetArray<char> ds(vertices);

    // Ordenar las aristas en función del peso
    sort(aristas.begin(), aristas.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // Recorrer todas las aristas y agregar al árbol solución si no forma un ciclo
    for (const Edge& arista : aristas) {
        char initParent = ds.Find(arista.init - 'A');
        char endParent = ds.Find(arista.end - 'A');

        if (initParent != endParent) {
            solucion.push_back(arista);
            ds.Union(initParent, endParent);
        }
    }

    return solucion;
}

void mostrar_ordenado(vector<Edge> result){
    for (const Edge& edge : result) {
        cout << edge.init << " - " << edge.end << " : " << edge.weight << endl;
    }
}