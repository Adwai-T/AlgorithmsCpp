/*
* Not efficient queue.
* Queue can be more effectively implemented as a linked list.
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Queue
{
private:
  string id;
  vector<T> queue;

public:
  Queue(string id) 
  {
    cout << "New Queue Created. ID : " << id << endl;
  }

  ~Queue()
  {
    //Just in case the queue is not destroied when the vector goes out of scope.
    queue.clear();
    cout << "Queue Destroied." << endl;
  }

  string getID()
  {
    return id;
  }

  void enqueue(T const &element)
  {
    queue.insert(queue.begin(), element);
    //- Insert for vector takes linear time
    //- Using linked list type data structure
    //will make queue and dequeue constant time.
  }

  T dequeue()
  {
    T removed = queue[queue.size() -1];
    queue.pop_back();
    return removed;
  }

  T peek()
  {
    return queue.back();
  }

  bool isEmpty()
  {
    return (queue.size() == 0) ? true : false;
  }

  void printQueue()
  {
    cout << "Queue with id : " << id << " { ";

    for(typename vector<T>::iterator it = queue.begin(); it != queue.end(); it++)
    {
      cout << *it << ", ";
    }

    cout << "\b\b }; " << endl;
  }

//THere could also be a method isFull() if we have a queue size limit.
};

int main()
{
  cout << "start" << endl;
  
  Queue<int> queue("Q1");
  cout << "Is Queue with id " << queue.getID() << " Empty : " << queue.isEmpty() << endl;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  cout << "Is Queue with id " << queue.getID() << " Empty : " << queue.isEmpty() << endl;

  queue.printQueue();

  cout << "peek first element : " << queue.peek() << endl;

  cout << "Remove and get first : " << queue.dequeue() << endl;

  queue.printQueue();
  
  cout << "end" << endl;
}