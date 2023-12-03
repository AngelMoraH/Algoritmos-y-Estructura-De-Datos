#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    T data;
    Node *left;
    Node *right;
};

void print_by_levels(Node* root){
    Node *temp = root;
    queue<Node*> queue2;
    queue2.push(root);

    while (!queue2.empty()){
        cout<<queue2.front()->data<<" ";
        temp = queue2.front();
        queue2.pop();
        if (temp->left != nullptr)
        {
            queue2.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            queue2.push(temp->right);
        }
        cout<<endl;
    }
}

int main(){
    return 0;
}