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
