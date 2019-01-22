# Linked Lists, Stacks, and Queues

## Lists
**Lists** are common abstract data types for storing ordered information. The two primary lists that we will deal with in this class are **Arrays** and **Linked Lists**

###### Arrays

**Arrays are great in that they are easy to use when we know _exactly how much data we are trying to store._**  If you have an exact amount of elements of the same data type, an array is the easest way to store this data. Rather verbosely,
> An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

Essentially, arrrays store a lot of data of *one type* in *one spot in memory*, and you can access the specifc data stored by way of an index. This index is appended to the name of the array between square brackets \[].

There are many ways to create arrays in C++, but these are the most common.

If we know the elements in the array and the array isn't overly large, 

`int[] myNums = {0, 1, 2, 3};` 

Otherwise, we can initialize the array with no values and populate later, 
```
int nums[4]; //We initialize the array...

for(int i = 0; i < 4;i++){ //And then we populate it.

  nums[i] = i;
  
}
```
Quick note: try to populate your array as you initialize it or immediately after you do so, for your own sanity. 

**Arrays are also great because _we can access any element in the array in constant O(1) time_. This comes in handy when implementing more complicated data structures, like hashtables!**

Where arrays start to fail, however, is when we don't know exactly how many elements we need to store. For that, we have...


###### Linked Lists

Linked Lists are especially useful when we **_don't know how many elements we are going to be storing at the time of initialization_**. 

Instead of storing data in _one spot in memory_, we can store it in multiple places and simply have the current element tell you where the next one is. 

A linked list is a series of **_nodes_** or **_links_** (depending on who you ask), objects containing 2 parts: a data section and a 'next' reference section.

```
class Node {
    public:
        int value;
        Node* next = NULL;
};
```
For this node, out data is an `int` and our reference to the next node `Node* next` is set to null.
This node becomes a part of a list when it either **a)** is referenced by another node as that node's next and/or **b)** references another node as its next.

Linked Lists can contain more than just a single data type as their data. In fact, a Node can contain as much data as you want, as long as you set up your node correctly. For example, let's have a linked list of dogs, where each dog has its own name, breed, and goodboi factor. We can either have a linked list where each node contains dog objects:

```
class Dog {
	public:
		String name;
		String breed;
		int goodboiFactor;
};

class Node {
  public:
		Dog dog;
		Node* Next = NULL;
};
```
or a Linked List with nodes containing information about the dog
```
class DogNode {
  public:
  	String name;
    String breed;
    int goodboiFactor;
		DogNode* NEXT = NULL;
};
```
Be careful and considerate with implementation of nodes!

On average, the computational complexity of adding to and removing from a linked list is O(1), where access to a specific node is O(n).

There are ways to implement linked lists, but there are a few that pop up a lot:

Single-Linked Lists
- A linked list where every node *only has reference to the next node in the list*
- During traversal, you can only step through the list in order, you can't find the previous node from any individual starting point

Doubly-Linked list
- A linked list where every node *has reference to both the previous node in the list and the next node in the list.*
- During traversal, you can go both forward and backward in the list, but things get messing when trying to implement methods that add and remove from the list (pointer magic)

Circular Linked List
- A linked list where the final node of the lost points to the head of the list
- Traversing these lists often utilize the concept of slow & fast pointers (We can talk about this in class if there is interest)




## Stacks and Queues

###### Stacks
A stack is an ADT that follows the LIFO (Last In, First Out) concept. **Stacks are very useful when we are only ever dealing with the _most recent_ data item that we are working with**
Think of it as a stack of blocks. 
You can always add a block to the top, but taking from the middle will probably mess things up. 

Adding to the top of the stack is referred to as *pushing* to the stack. Removing is referred to as *popping* from the stack. 
Both pushing and popping are **O(1)** operations. 
When you pop something off the stack, it is removed from the stack and is no longer accessible through the stack.
Some implementations of the stack allow for an operation called *peek*, returning the top of the stack without removing it.
Careful about the distinction between pop and peek!

There are a few ways to implement a stack in code. In this course, we discuss **array-based stacks** and **reference-based stacks**.

**Array-Based Implementaion**
 - pop operation simply returns the item at the greatest *filled* index. 
 - push operation will add to the end of the *filled* array indices. 
 
**Reference-based implementation**
- pop operation will unlink the last node in the list and return it. (We'll go over this on Monday)
- push operation sets the last node's next to the data being pushed on the stack. (We'll also go over this on Monday)

Stacks are used behind the scenes in code all the time. For example, when you write a method/function that calls another method/function, the original method and all of its non-global variable are saved to a stack frame so that execution can continue when the called method has finished its own execution. 
This is how recursion works. All of the method calls are pushed to a stack until a base case is reached. Then, each preceding call is popped off the stack so that it can finish execution. 



###### Queues
A queue, conversely, is an ADT that follows the FIFO (First In, First Out) concept. 
Think of it as a line in a grocery store.  
The first person in the line is the first to get serviced.

Adding to the queue of the stack is still referred to as *pushing* or *enqueuing*, but the item is pushed to the **back** of the queue. 
Removing is referred to as *popping* or *dequeuing* from the queue. 
Both pushing/enqueuing and popping/dequeuing are **O(1)** operations. 



