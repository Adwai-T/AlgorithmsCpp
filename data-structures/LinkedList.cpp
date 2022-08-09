/*
  Singly Linked List.
  New Nodes are added at head and removed from head.
  Can add, get and remove nodes from any index.
*/

#include <iostream>

using namespace std;

template<class T>
struct Node
{
  T data;
  struct Node<T> *next;
};

template <class T>
class LinkedList
{
private :
  int size = 0;
  string id;
  struct Node<T> *head = NULL;

  struct Node<T>* getNodeAtIndex(int index)
  {
    if(index >= size) return NULL;

    struct Node<T> *node = head;
    for(int i=1; i < index; i++)
    {
      node = head->next;
    }
    return node;
  }

public :
  LinkedList()
  {
    cout << "LinkedList Created." << endl;
  }

  ~LinkedList()
  {
    this->clear();
    cout << "LinkedList destroied." << endl;
  }

  void add(T const &t)
  {
    struct Node<T> *node = new Node<T>();
    node->data = t;
    node->next = NULL;

    if(size == 0)
    {
      head = node;
    }
    else
    {
      struct Node<T> *temp = head;
      head = node;
      head->next = temp;
    }

    size++;
  }

  void addAt(int index, T const &t)
  {
    struct Node<T>* prev = getNodeAtIndex(index);
    if(prev == NULL) return;
    
    struct Node<T> *node = new Node<T>();
    node->data = t;
    node->next = prev->next;
    prev->next = node;

    size++;
  }

  T get(int index)
  {
    struct Node<T> *node = getNodeAtIndex(index);
    return node->data;
  }

  T peek()
  {
    return head->data;
  }

  T removeHead()
  {
    if(size == 0) return NULL;
    struct Node<T> *removed = head;
    head = head->next;
    T t = removed->data;
    delete(removed);
    size--;
    return t;
  }

  T removeAt(int index)
  {
    if(index==0) 
    {
      removeHead();
      return NULL;
    }
    if(index<0) return NULL;

    struct Node<T> *prev =  getNodeAtIndex(index-1);
    struct Node<T> *node = prev->next;
    T t = node->data;
    prev->next = node->next;
    delete(node);
    size--;
    return t;
  }

  /*
    When list is cleared each element should be deleted
    individually as they will still remain in dynamic
    memory when the list is destroied with no way to reach,
    causing memory leak.
  */
  void clear() {
    while(size != 0) {
      removeHead();
    }
    cout << "Linked List Cleared" << endl;
  }

  int length() 
  {
    return size;
  }

  string getId()
  {
    return id;
  }

  void setId(string id)
  {
    this->id = id;
  }

  void printAll()
  {
    struct Node<T> *node = head;
    cout << "Length : " << size << endl;
    cout << "{ ";
    for(int i = 0; i < size; i++)
    {
      cout << node->data << ", ";
      node = node->next;
    }

    cout << "\b\b }" << endl;
  }
};

int main()
{
  cout << "Start" << endl;

  LinkedList<string> ll;
  ll.add("Adwait");
  ll.add("Sakshi");
  ll.add("Vikas");
  ll.add("Sandipan");
  string name = "Tom";
  string* name_ptr = &name;
  ll.add(name);

  ll.printAll();

  cout << "Remove at Head : " << ll.removeHead() << endl; 
  cout << "Remove at index 1 : " << ll.removeAt(1) << endl;

  ll.addAt(2, "Jim");

  ll.printAll();

  cout << "End" << endl;
}