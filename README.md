# Linked Lists / Stacks / Queues
These are the first set of data structures you will be introduced to. The implementations shown here will be simple but they can be expanded.

## Linked Lists
Linked lists are a data structure used to store data. This is a pretty broad statement, but they essentially perform the same functions as an array but with some pros. and cons.

The easiest way for me to explain their usage, would be to explain the differences between a linked list and an array.

### Arrays vs Linked Lists
Linked Lists | Arrays
--- | ---
Not in continuous memory (each node points to the next) | In contiguous memory
Can be any size (given OS and hardware limitations) and resize | Fixed size in memory
Must iterate through to find a given element (O(n) access time) | Direct indexing (O(1) access time)


### Singly Linked Lists (SLL)
This is the first type of list that will be talked about. A singly linked list consists of nodes, connected by pointers. A singly linked list is only connected "one way" with each node in the list pointing to the next. All examples I will show are linked list based implementations. There are array based implementations for each of these data structures, but they are not shown here.

Here is an example of an SSL class:

```c++
#pragma once
//because this class is templated, all functionality must be included in this file (header file) because C++ must know the value of T at compile time.
#include <stdexcept>
#include <iostream>

template <typename E>
class SLL
{
 public:
  SLL();
  ~SLL();
  void insert_at( E value , unsigned int position);
  E remove_item_at(unsigned int position);
  void append(E value);
  void prepend(E value);
  void print();
  unsigned int replace(E value, E replacement);

  int length();
  inline bool is_empty(){return head == nullptr;}
 private:
  struct Node;
  Node* head;
};//class sll

template <typename E>
struct SLL<E>::Node
{
  Node* next;
  E data; 
};//struct Node
```
## Stacks
Stacks are linear data structures that serve as storage of objects. Items are inserted and removed by the Last In First Out (LIFO) principle.

'''c++
#pragma once

//because this class is templated, all functionality must be included in this file (header file) because C++ must know the value of T at compile time.
#include <stdexcept>
#include <iostream>

template <typename E>
class Stack
{
public:
	Stack();
	~Stack();
	void push(E value);
	E pop();
	E peek();
	int size();
	inline bool is_empty() { return top == nullptr; }
private:
	int size;
	struct Node;
	Node* top;
};//class stack

template <typename E>
struct SLL<E>::Node
{
	Node* previous;
	E data;
};//struct Node

'''

## Queues
Similar to stacks, queues are also linear data structures that store objects. The difference being that items inserted and removed from queues follow the First In First Out (FIFO) principle. So the first item queued will be the first item to be removed on a dequeue.

'''c++
#pragma once

//because this class is templated, all functionality must be included in this file (header file) because C++ must know the value of T at compile time.
#include <stdexcept>
#include <iostream>

template <typename E>
class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(E value);
	E peek();
	E dequeue();
	int size();
	inline bool is_empty() { return front == nullptr; }
private:
	int size;
	struct Node;
	Node* front;
};//class queue

template <typename E>
struct SLL<E>::Node
{
	Node* next;
	E data;
};//struct Node

'''
