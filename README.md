# Linked Lists / Stacks / Queues / Recursion
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
This is the first type of list that will be talked about. A singly linked list consists of nodes, connected by pointers. A singly linked list is only connected "one way" with each node in the list pointing to the next. 

Here is an example of an SSL class:

<pre><code>
#pragma once

//because this class is templated, all functionality must be included in this file (header file) because C++ must know the value of T at compile time.
template <typename T>
class SLL {
	
	public:
		SLL(); //constructor
		~SLL(); //destructor 
		
		//SLL functions you may want, add more to add more functionality
		void append();
		void prepend();
		void remove_by_value(const T& value); //should this remove all instances of the value? or just the first?
		void remove_by_index(const int index);
		T& value_at(const int index);
		T& find(const T& value);
		void print();
		
		inline T& operator[](const int &index){return this->value_at(index);} //Now you can use it like an array
	private:
		int _size; //easy way to keep track of size so we dont need to make an O(n) function to count constantly. The underscore is the naming convention for C/C++ member variables

		struct node{
			public:
				node(); //constructor
				~node(); //destructor
			private:
				T data; //can store any datatype, class is templated
				node* _next; //next node in the list
		};//end node

		node* _head;
		//node _tail; //You may want to keep a tail pointer, but this isnt necessary.

};//end SLL
</code></pre>
