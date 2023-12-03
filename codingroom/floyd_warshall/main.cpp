#include <iostream>
#include "solucion.h"

using namespace std;

void test1(){
    vector<char> vertices = {'1','2','3','4','5'};
    vector<Edge> aristas = 
        {{'1', '3', 6},
        {'1', '4', 3},
        {'2', '1', 3},
        {'3', '4', 2},
        {'4', '2', 1},
        {'4', '3', 1},
        {'5', '2', 4},
        {'5', '4', 2}
        };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '5','1');//5->4->2->1
    displayPath(tourMatrix, '2','3');//2->1->4->3
    displayPath(tourMatrix, '5','3');//5->4->3
}

void test2(){
    vector<char> vertices = {'1','2','3','4'};
    vector<Edge> aristas = 
        {{'1', '3', -2},
        {'2', '1', 4},
        {'2', '3', 3},
        {'3', '4', 2},
        {'4', '2', -1}
        };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '2','3');//2->1->3
    displayPath(tourMatrix, '4','3');//4->2->1->3
    displayPath(tourMatrix, '2','4');//2->1->3->4    
}

int main(){
    test1();
    test2();
}