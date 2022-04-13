
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
const int QUEUE_CAPACITY = 6;
template<class QueueElement>
class Queue
{
 public:
  Queue();
  bool empty() const;
  void enqueue(const QueueElement & value);
  void display(std::ostream & out) ;
  QueueElement front() const;
  void dequeue();
  bool full()
{
   return ((myBack + 1) % QUEUE_CAPACITY)==myFront;
}
//Gets the amount of active elements in the queue
int getSize();
 private:
  QueueElement myArray[QUEUE_CAPACITY];
  int myFront,
      myBack;
}; // end of class declaration
template<class QueueElement>

Queue<QueueElement>::Queue()
: myFront(0), myBack(0)
{}

template<class QueueElement>
bool Queue<QueueElement>::empty() const
{
   return (myFront == myBack); 
}

template<class QueueElement>
void Queue<QueueElement>::enqueue(const QueueElement & value)
{
   int newBack = (myBack + 1) % QUEUE_CAPACITY;
   if (newBack != myFront)     // queue isn't full
   { 
      myArray[myBack] = value;
      myBack = newBack;
   }
   else
   {
	dequeue();
	myArray[myBack] = value;
	myBack = newBack;
   }
}

template<class QueueElement>
void Queue<QueueElement>::display(std::ostream & out) 
{
   for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
   	myArray[i].display();
   std::cout << std::endl;
}

template<class QueueElement>
QueueElement Queue<QueueElement>::front() const
{
   if ( !empty() ) 
      return (myArray[myFront]);
   else
   {
      std::cerr << "*** Queue is empty "
              " -- returning garbage value ***\n";
      return myArray[QUEUE_CAPACITY-1]; // "Garbage" value
   }
}

template<class QueueElement>
//--- Definition of dequeue()
void Queue<QueueElement>::dequeue()
{
   if ( !empty() )
      myFront = (myFront + 1) % QUEUE_CAPACITY;
  
} 
template<class QueueElement>
//---- Definition of getSize()
int Queue<QueueElement>::getSize()
{
    int counter=0;
    for(int i=myFront;i!=myBack; i = (i + 1)%QUEUE_CAPACITY)
	counter++;
    return counter;
}
#endif //QUEUE_H
