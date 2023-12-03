#include <iostream>
#include "chainhash.h"

using namespace std;

int main(){
    ChainHash<string, int> umap;
  
    umap.insert("utec",1);
    umap.insert("san marcos", 2);
    umap.insert("pucp", 3);
    umap.insert("ucal", 4);
    umap.insert("upc", 5);
    umap.insert("utp", 6);
    umap.insert("upch", 7);
    umap.insert("unam", 8);
    umap.insert("unt", 9);
    umap.insert("usp", 10);
    umap.insert("San Martin", 8);
    umap.insert("upuch", 10);
    umap.insert("patito", 6);
    umap.insert("ugod", 6);

    int n = umap.bucket_count();
    cout<<"size of hash table:"<<n<<endl;
    for(int i=0;i<n;++i){
        cout<<"Bucket #"<<i<<", size: "<<umap.bucket_size(i)<<":  ";
        for(auto it = umap.begin(i); it != umap.end(i); ++it){
            cout<<"["<<(*it).key<<":"<<(*it).value<<"]";
        }
        cout<<endl;
    }

    cout<<"find utec: "<<umap.find("utec")<<endl;
    cout<<"find unam: "<<umap.find("unam")<<endl;
    cout<<"find upc: "<<umap.find("upcc")<<endl;
} 