#include <iostream>
#include <vector>
using namespace std;

/*template<typename T>
struct Node {
        int row;
        int col;
        T val;
        Node<T> *next;
};

template<typename T>
class SparseMatrix {
private:
    int rows;
    int cols;
    Node<T>* head;
public:
    SparseMatrix(int _rows, int _cols):rows(_rows),cols(_cols){
        head = nullptr;
    }
    void insert(int _row, int _col, T value){
        Node<T>* newNodo = new Node<T>;
        newNodo->row = _row;
        newNodo->col = _col;
        newNodo->val = value;
        newNodo->next = nullptr;
        if(head == nullptr){
            head = newNodo;
        }else{
            Node<T>* temp = this->head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNodo;
        }
    }
    bool isEmpty(){
        return this->head==nullptr ? true : false;
    }
    bool compareSparseMatrix(SparseMatrix<T> &matrix2){
        Node<T>* temp1 = this->head;
        Node<T>* temp2 = matrix2.head;

        if(this->rows != matrix2.rows || this->cols != matrix2.cols){
            return false;
        }
        if(this->isEmpty() && matrix2.isEmpty()){
            return true;
        }
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->row!=temp2->row|| temp1->col!=temp2->col||temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1==nullptr && temp2==nullptr;
    }
};*/
template<typename T>
struct Node {
        T data;
        int pos_row;
        int pos_col;
        Node *next_row;
        Node *next_col;
    };
template<typename T>
struct SparseMatrix {
    
    vector<Node<T> *> rows;
    vector<Node<T> *> cols;
    int n_cols;
    int n_rows;
};

template <typename T>
void showSparseMatrix(const SparseMatrix<T>& original)
{
    for (int i = 0; i < original.n_rows; i++)
    {
        Node<T>* temp = original.rows[i];
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next_row;
        }
        cout << endl;
    }
}

template<typename T>
void deleteColumn(const SparseMatrix<T>& matriz, int columna){
    if(columna<0||columna>=matriz.n_cols){
        return;
    }
    for(int i=0;i<matriz.cols[columna]->pos_row;i++){
        
    }
}

int main()
{
    SparseMatrix<int> matrix;
    matrix.n_rows = 3;
    matrix.n_cols = 3;
    matrix.rows.resize(matrix.n_rows);
    matrix.cols.resize(matrix.n_cols);
    // Datos de la matriz original
    int data[3][3] = {
        {1, 2, 0},
        {0, 0, 3},
        {4, 0, 5}};

    // Inserción de datos en la matriz original
    for (int i = 0; i < matrix.n_rows; i++)
    {
        for (int j = 0; j < matrix.n_cols; j++)
        {
            if (data[i][j] != 0)
            {
                Node<int> *new_node = new Node<int>;
                new_node->pos_row = i;
                new_node->pos_col = j;
                new_node->data = data[i][j];
                new_node->next_col = nullptr;
                new_node->next_row = nullptr;

                if (matrix.rows[i] == nullptr)
                {
                    matrix.rows[i] = new_node;
                    matrix.cols[j] = new_node;
                }else{
                    cout<<"prueba: "<< matrix.rows[i] <<endl;
                }
                /*else
                {
                    Node<int> *current = matrix.rows[i];
                    while (current->next_row != nullptr)
                    {
                        current = current->next_row;
                    }
                    current->next_row = new_node;

                    current = matrix.cols[j];
                    while (current->next_col != nullptr)
                    {
                        current = current->next_col;
                    }
                    current->next_col = new_node;
                }*/
            }
        }
    }

    // Mostrar la matriz original
    cout << "Matriz original:" << endl;
    showSparseMatrix(matrix);

    // Obtener la matriz transpuesta
    //SparseMatrix<int> transposed = transpose(matrix);

    // Mostrar la matriz transpuesta
    cout << "Matriz transpuesta:" << endl;
    //showSparseMatrix(transposed);

    // Liberar memoria de la matriz original
    /*for (int i = 0; i < matrix.n_rows; i++)
    {
        Node<int> *temp = matrix.rows[i];
        while (temp != nullptr)
        {
            Node<int> *temp2 = temp;
            temp = temp->next_row;
            delete temp2;
        }
    }

    // Liberar memoria de la matriz transpuesta
    for (int i = 0; i < transposed.n_rows; i++)
    {
        Node<int> *temp = transposed.rows[i];
        while (temp != nullptr)
        {
            Node<int> *temp2 = temp;
            temp = temp->next_row;
            delete temp2;
        }
    }*/

    return 0;
}