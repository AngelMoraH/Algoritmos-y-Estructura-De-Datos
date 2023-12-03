#include <vector>
using namespace std;

template<typename T>
class DisjoinSetArray
{
private:
    vector<T> data;
    int* parents;
    int* rank;
public:
   DisjoinSetArray(vector<T> data){
       this->data = data;
       this->parents = new int[data.size()];
       this->rank = new int[data.size()];
       makeset();
   } 

    void makeset()
    {
        for(typename vector<T>::size_type i=0;i<data.size();i++)
        {
            this->parents[i] = i;
            this->rank[i] = 0;
        }
    }

    int Find(int index){
        if(index == parents[index]) return index;
        else return Find(parents[index]);
    }
   
   void Union(int x, int y){
       int rootX = Find(x);
       int rootY = Find(y);

       if (rootX != rootY) {
           if (rank[rootX] < rank[rootY]) {
               parents[rootX] = rootY;
           } else if (rank[rootX] > rank[rootY]) {
               parents[rootY] = rootX;
           } else {
               parents[rootY] = rootX;
               rank[rootX]++;
           }
       }
   }

   int sets(){
       int count = 0;
       for (typename vector<T>::size_type i = 0; i < data.size(); i++) {
           if (parents[i] == static_cast<int>(i)) {
               count++;
           }
       }
       return count;
   }

   bool isConnected(int x, int y){
       return Find(x) == Find(y);
   }
   
   vector<T> getElementsSet(int index) {
    int root = Find(index);
    vector<T> elementsSet;
    for (typename vector<T>::size_type i = 0; i < data.size(); i++) {
        if (Find(static_cast<int>(i)) == root) {
            elementsSet.push_back(data[i]);
        }
    }
    return elementsSet;
}

};