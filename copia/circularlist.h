#include <iostream>

using namespace std;

class CircularList
{
private:
    struct Node
    {
        string data;
        Node *next;
        Node *prev;

        Node()
        {
            this->data = "";
            this->next = nullptr;
            this->prev = nullptr;
        }

        Node(string value)
        {
            this->data = value;
            this->next = nullptr;
            this->prev = nullptr;
        }

        void killSelf()
        {
            if (next != nullptr)
            {
                next->killSelf();
            }
            delete this;
        }
    };

private:
    Node *head; // sentinel
    int nodes;

public:
    CircularList()
    {
        this->head = new Node();
        this->head->next = head;
        this->head->prev = head;
        this->nodes = 0;
    }

    ~CircularList()
    {
    }

    string front()
    {
        if (is_empty())
        {
            throw "List esta vacio";
        }
        return head->next->data;
    }

    string back()
    {
        if (is_empty())
        {
            throw "List esta vacio";
        }
        return head->prev->data;
    }

    Node *getHead()
    {
        return head;
    }

    void push_front(string data)
    {
        Node *new_node = new Node(data);
        if (is_empty())
        {
            new_node->prev = head;
            new_node->next = head;
            head->next = new_node;
            head->prev = new_node;
        }
        else
        {
            new_node->prev = head;
            new_node->next = head->next;
            head->next->prev = new_node;
            head->next = new_node;
        }
        nodes++;
    }

    void push_back(string data)
    {
        Node *new_node = new Node(data);
        if (is_empty())
        {
            new_node->prev = head;
            new_node->next = head;
            head->next = new_node;
            head->prev = new_node;
        }
        else
        {
            new_node->prev = head->prev;
            new_node->next = head;
            head->prev->next = new_node;
            head->prev = new_node;
        }
        nodes++;
    }

    string pop_front()
    {
        if (is_empty())
        {
            throw "List esta vacia";
        }
        Node *temp = head->next;
        string data = temp->data;

        if (nodes == 1)
        {
            head->next = head;
        }
        else
        {
            head->next = temp->next;
            head->next->prev = head;
        }
        delete temp;
        temp = nullptr;
        nodes--;
        return data;
    }

    string pop_back()
    {
        if (is_empty())
        {
            throw "List is empty";
        }
        string data = head->prev->data;
        head->prev = head->prev->prev;
        head->prev->next = head;
        nodes--;
        return data;
    }

    string insert(string data, int pos)
    {
        if (pos < 0 || pos > nodes)
        {
            throw "Invalid position";
        }
        if (pos == 0)
        {
            push_front(data);
            return data;
        }
        else if (pos == nodes)
        {
            push_back(data);
            return data;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }
            Node *new_node = new Node(data);
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            nodes++;
            return data;
        }
    }
    void setNode(int node)
    {
        this->nodes = node;
    }

    bool remove(int pos)
    {
        if (pos < 0 || pos >= nodes)
        {
            return false;
        }
        Node *current = head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        if (nodes == 1)
        {
            head = nullptr;
        }
        else
        {
            if (current == head)
            {
                head = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        nodes--;
        return true;
    }

    bool is_empty()
    {
        if (nodes == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string &operator[](int pos)
    {
        if (pos < 0 || pos >= nodes)
        {
            throw "Invalid position";
        }
        Node *current = head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void print()
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *current = head->next;
            while (current != head)
            {
                cout << current->data << "";
                current = current->next;
            }
            cout << endl;
        }
    }

    int size()
    {
        return nodes;
    }
    void clean()
    {
        while (nodes > 0)
        {
            pop_front();
        }
    }
};