#include <iostream>
#include <string>

using namespace std;
template <typename T>
class Set
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        void killself()
        {
            if (left != nullptr)
            {
                left->killself();
            }
            if (right != nullptr)
            {
                right->killself();
            }
            delete this;
        }
    };
    Node *root;
    void insert(Node *&node, T data)
    {
        if (node == nullptr)
        {
            Node *temp = new Node();
            temp->data = data;
            node = temp;
        }
        else if (node->data >= data)
        {
            insert(node->left, data);
        }
        else
        {
            insert(node->right, data);
        }
        return;
    }
    void displayInOrder(Node *&node, string &value)
    {
        if (node == nullptr)
        {
            return;
        }
        displayInOrder(node->left, value);
        value += to_string(node->data);
        value += " ";
        displayInOrder(node->right, value);
    }
    T minValue(Node*& node){
        Node *temp = node;
        while(true){
            if(temp->left == nullptr){
                break;
            }
            temp= temp->left;   
        }
        return temp-> data;
    }

    void remove(Node *&node, T value)
    {
        if(node == nullptr) return;
        if (value < node->data){
            remove(node->left, value); 
        }else if (value > node->data){
            remove(node->right, value); 
        }else{
                // caso 1: hoja
                if (node->left == nullptr && node->right == nullptr)
                {
                    delete node;
                    node = nullptr;
                }
                // caso 2: tiene hijo derecho
                else if (node->left == nullptr)
                {
                    Node *temp = node;
                    node = node->right;
                    delete temp;
                }
                // caso 2: tiene hijo izquierdo
                else if (node->right == nullptr)
                {
                    Node *temp = node;
                    node = node->left;
                    delete temp;
                }
                // caso 3: tiene dos hijos
                else
                {
                    T sucesor = minValue(node->right);
                    node->data = sucesor;
                    remove(node->right, sucesor);
                }
            }
    }

public:
    Set()
    {
        root = nullptr;
    }
    void Insert(T data)
    {
        if (!this->Contains(data))
        {
            this->insert(this->root, data);
        }
        return;
    }

    bool Remove(T data)
    {
        if(this->Contains(data)){
            remove(this->root, data);
            return true;
        }
        return false;
    }
    bool Contains(T data)
    {
        Node *temp = this->root;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                return true;
            }
            else if (temp->data > data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    void display()
    {
        string value = "";
        this->displayInOrder(this->root, value);
        cout << value << endl;
    }
    Set Union(const Set &other);
    Set Intersect(const Set &other);
    Set Difference(const Set &other);
    ~Set()
    {
        if (root != nullptr)
        {
            root->killself();
        }
    };
};
