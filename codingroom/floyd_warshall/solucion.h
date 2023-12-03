#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Estructura para representar una arista
struct Edge {
    char source;
    char destination;
    int weight;
    Edge(char _source, char _destination, int _weight) {
        this->source = _source;
        this->destination = _destination;
        this->weight = _weight;
    }
};

vector<vector<int>> FloydWarshall(vector<char> vertices,vector<Edge> aristas){
    const int INF = std::numeric_limits<int>::max();
    const int n = vertices.size();
    
    vector<vector<int>> data;
    vector<vector<int>> distancias;
    
    data.resize(n, vector<int>(n,0));
    distancias.resize(n, vector<int>(n,INF));

    for (int i = 0; i < n; i++) {
        data[i][i] = 0;
    }

    for (const auto& arista : aristas) {
        int i = arista.source - '1';
        int j = arista.destination - '1';
        distancias[i][j] = arista.weight;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j){ 
                data[i][j] = j+1;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                if(distancias[j][i] != INF && distancias[i][k] != INF && distancias[j][k] > (distancias[j][i] + distancias[i][k])) {
                    distancias[j][k] = distancias[j][i] + distancias[i][k];
                    if(j != i && i != k && j != k) data[j][k] = data[j][i];
                }    
            }
        }
    }
    return data;
}

// Función para mostrar el camino más corto entre dos vértices
void displayPath(const vector<vector<int>>& data, char ini, char end) {
    int i = ini - '1';
    int j = end - '1';

    if (data[i][j] == numeric_limits<int>::max()) {
        cout << "No hay camino entre " << ini << " y " << end << endl;
        return;
    }

    if (data[i][j] == 0 || data[i][j] == j + 1) {
        cout << ini << " -> " << end << endl;
        return;
    }

    cout << ini << " -> ";

    while (data[i][j] != j + 1) {
        cout << (char)(data[i][j] + '0') << " -> ";
        i = data[i][j] - 1;
    }

    cout << end << endl;
}