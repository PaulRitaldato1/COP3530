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
