#include <iostream>

using namespace std;

template<class T>
struct Node
{
    T data;
    Node *next;
};

template<class T>
class Stack
{
private:
    int size = 0;
    struct Node<T> *head = NULL;
public:
    void push(T const &t)
    {
        struct Node<T> *temp = new Node<T>();
        temp->data = t;
        temp->next = head;
        head = temp;
        size++;
    }
    T pop()
    {
        if(size < 1) return NULL;
        struct Node<T> *temp = head;
        head = head->next;
        size--;
        return temp->data;
    }
    T peek()
    {
        if(size < 1) return NULL;
        return head->data;
    }
    bool isEmpty()
    {
        return size < 1;
    }
    int getSize()
    {
        return this.size;
    }
    void printStack()
    {
        cout << "size : " << size << endl;
        cout << "{ ";
        struct Node<T> *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "\b\b }" << endl;
    }
};

int main() 
{
    Stack<int> stack;
    stack.push(10);
    stack.push(40);
    stack.push(30);
    stack.push(14);
    stack.printStack();
    cout << stack.peek() <<endl;
}

