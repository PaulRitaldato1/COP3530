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
	void insert_at(E value, unsigned int position);
	E remove_item_at(unsigned int position);
	void append(E value);
	void prepend(E value);
	void print();
	unsigned int replace(E value, E replacement);

	int length();
	inline bool is_empty() { return head == nullptr; }
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