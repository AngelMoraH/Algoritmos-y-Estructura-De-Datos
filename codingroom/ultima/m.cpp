#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <vector>

using namespace std;

const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789   ";

string generarTexto(size_t N){    
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() %  alfabeto.size()];
    return resultado;
}

vector<int> testInocente(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO
    vector<int> result;
    int n = Texto.length();
    int m = Patron.length();

    for (int i = 0; i <= n - m;)
    {
        int j = 0;
        while (j < m && Texto[i + j] == Patron[j]){
            j++;
        }
        if (j == m){
            result.push_back(i);
        }
        if (j == 0){
            i ++;
        } else{
            i += j;
        }
    }

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Inocente time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

vector<int> buildPositions(string Patron) {
    int m = Patron.length();
    vector<int> positions(256, -1);

    for (int i = 0; i < m - 1; i++)
        positions[Patron[i]] = i;

    return positions;

}



vector<int> testBoyerMoore(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO
    vector<int> result;
    int n = Texto.length();
    int m = Patron.length();
    vector<int> positions = buildPositions(Patron);
    int i = 0;
    while (i <= n - m){
        int j = m - 1;
        while (j >= 0 && Patron[j] == Texto[i + j]){
            j--;
        }

        if (j < 0){
            result.push_back(i);
            i += m;
        }else{
            if (j - positions[Texto[i + j]]> 0){
                i += j - positions[Texto[i + j]];
            }
                
            else{
                i += 1;
            }
                
        }
    }


    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "BoyerMoore time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

void verificarResultado(vector<int> result1, vector<int> result2)
{
    for(int i=0;i<static_cast<int>(result1.size());i++)
        cout << result1[i] << " ";
    cout << endl;
    for(int i=0;i<static_cast<int>(result2.size());i++)
        cout << result2[i] << " ";
    cout << endl;
    
    if(result1.size() != result2.size())
        cerr <<"Error!! el resultado no es el mismo\n";
    for(int i=0;i<static_cast<int>(result1.size());i++)
        if(result1[i] != result2[i])
            cerr <<"Error!! el resultado no es el mismo\n";
}


int main()
{    
    srand(time(NULL));    
    //size_t N = 20;//100,1000,10000,100000,1000000
    //int m = 10;
    //string Texto = generarTexto(N);
    //string Patron = generarTexto(m);       
    string Texto = "AABAACAADAABAABA";//GCGATGCCTA
    string Patron = "AABA";//TATATG
    
    vector<int> result1 = testInocente(Texto, Patron);
    vector<int> result2 = testBoyerMoore(Texto, Patron);
    verificarResultado(result1, result2);

    return 0;
}
/*
int main()
{    
    srand(time(NULL));    
    size_t N = 1000000;//100,1000,10000,100000 x,1000000
    int m = 10;
    string Texto = generarTexto(N);
    string Patron = generarTexto(m);    
    
    vector<int> result1 = testInocente(Texto, Patron);
    vector<int> result2 = testBoyerMoore(Texto, Patron);
    verificarResultado(result1, result2);

    return 0;
}*/
