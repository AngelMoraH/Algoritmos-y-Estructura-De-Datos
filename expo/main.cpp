#include <iostream>
using namespace std;
//https://chalk.ist/
void countingSort1(int array[], int size){
    int output[size];
    int max = array[0];

    for (int i = 0; i < size; i++) {
        max = array[i] > max ? array[i] : max;
    }

    int count[max+1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for(int i=0; i<size; i++){
        output[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void countingSort2(int array[], int size){
    int output[size];
    int max = array[0];

    for (int i = 0; i < size; i++) {
        max = array[i] > max ? array[i] : max;
    }

    int count[max];

    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]-1]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for(int i=0; i<size; i++){
        output[count[array[i]-1]-1] = array[i];
        count[array[i]-1]--;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int main(int argc, char const *argv[]) {
    clock_t start, end;
    int n=7;
    int array[n] = {4, 2, 2, 8, 3, 3, 1};
    cout<<"Unsorted array: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    countingSort2(array, n);
    cout<<"Sorted array: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
