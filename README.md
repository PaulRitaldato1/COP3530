# Recursion and Binary Search Trees

## Recursion 
Here are some code samples of recursion used in a SLL. The example shows a decentralized SLL. This means that the majority of the functionality is not inside the SLL class as you will ssee!

```c++
#ifndef _SLL_H_
#define _SLL_H_

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
  
    public:
        void insert_at( E value , unsigned int position);
        E remove_item_at(unsigned int position);
        void append(E value);
        void print();
        unsigned int replace(E value, E replacement);

        int length();

 
};//struct Node

/*=================================================== BEGIN SLL FUNCTIONS ===================================================*/

//constructor and method definitions for SLL
template <typename E>
SLL<E>::SLL()
{
    head = nullptr;
}

//print
template <typename E>
void
SLL<E>::print()
{
std::cout << "{";
if(head)
    head->print();
std::cout << " }";
}

template <typename E>
int
SLL<E>::length()
{
if(!head)
   return 0;
return head->length();
}

template <typename E>
void SLL<E>::insert_at(E value, unsigned int position)
{
    if(position == 0)
    {
      prepend(value);
    }
  if(position > (head->length()))
    {
      head->append(value);
    }
  else
    head->insert_at(value, position);
}

template <typename E>
void
SLL<E>::prepend(E value)
{
  Node* tmp = new Node();
  tmp -> data = value;
  tmp -> next = head;
  head = tmp;
}

template <typename E>
void
SLL<E>::append( E value )
{
if(head)
  {
    head->append(value);
  }
else
  prepend(value);
}

template <typename E>
E
SLL<E>::remove_item_at(unsigned int position)
{
  if(position > head->length())
    std::cout << "position does not exist";
  else
    head->remove_item_at(position);
}

template <typename E>
unsigned int
SLL<E>::replace(E value, E replacement)
{
  if(head)
    return head->replace(value, replacement);
  else
    return 0;
}


/*=================================================== END SLL FUNCTIONS ===================================================*/

/*=================================================== BEGIN NODE FUNCTIONS ===================================================*/
template <typename E>
void
SLL<E>::Node::print(){
std::cout << " " << data;
if (next){
    std::cout << " -> ";
    next->print();
  }
}



template <typename E>
int
SLL<E>::Node::length()
{
if (!next)
  return 1;
return 1 + next->length();
}

template <typename E>
void
SLL<E>::Node::append( E value )
{
  if(next)
  {
  next->append(value);
  }
  else
  {
   
    Node* temp = new Node;
    temp -> data = value;
    temp -> next = nullptr;

    next = temp;

  }
}

template <typename E>
void
SLL<E>::Node::insert_at(E value, unsigned int position)
{

  if(position == 1)
    {
      Node* tmp = new Node;
      tmp -> data = value;
      tmp -> next = next;
      next = tmp;
    }
  else
    next->insert_at(value, position-1);
}


template <typename E>
E
SLL<E>::Node::remove_item_at(unsigned int position)
{
  if(position == 0)
    {
      next = next->next;
      return next-> data;
    }
  else
    return remove_item_at(position-1);
}

template <typename E>
unsigned int
SLL<E>::Node::replace(E value, E replacement)
{
  if(next)
    return 0;
  if(value == data)
    {
      data = replacement;
      return 1 + next -> replace(value, replacement);
    }
  else
    return next -> replace(value, replacement);
}

/*=================================================== END NODE FUNCTIONS ===================================================*/
#endif
```

## BST Example
```c++
#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include <stdexcept>

template <typename E>
class BST
{
    private:
        struct Node;
        Node* root;
    public:
        BST();
        unsigned int shortest_branch_length();
        unsigned int do_shortest_branch_length(Node* place);
        void insert( E value);
        bool contains(E value);
        unsigned int size();
        E* contents_as_array();
        bool do_contains(E value, Node* place);
        unsigned int do_size(Node* place);
        void do_insert(E value, Node* place);
        E* do_contents_as_array(E* array, Node* place);
        bool is_leaf(Node* place){
            if(place->left == nullptr && place->right == nullptr)
                return true;
            else
                return false;
            }
};//class bst

template <typename E>
struct BST<E>::Node
{
  
 Node(E value): left(nullptr), right(nullptr), count(1), data(value)
  {}

  Node* left;
  Node* right;
  int count;
  E data;
};
  
//constructor and method definitions
template <typename E>
BST<E>::BST() : root(nullptr){}

//insert
template <typename E>
void
BST<E>::insert(E value)
{
  if(!root)
    root = new Node(value);
  else
    {
      do_insert(value, root);
    }
}
template <typename E>
void
BST<E>::do_insert(E value, Node* place)
{
  if(value == place->data)
    if(place->right)
      do_insert(value, place->right);
    else
      place->right = new Node(value);
  else if(value < place->data)
    if(place->left)
      do_insert(value, place->left);
    else
      place->left = new Node(value);
  else
    if(place->right)
      do_insert(value, place->right);
    else
      place-> right = new Node(value);
}//end insert

template <typename E>
bool
BST<E>::contains(E value)
{
  if(!root)
    return 0;
  else
    {
      return do_contains(value, root);
    }
}

template <typename E>
bool
BST<E>::do_contains(E value, Node* place)
{
  if(is_leaf(place))
    return 0;
  if(value == place->data)
    return 1;
  else if(value < place->data)
    if(place->left)
      do_contains(value, place->left);
    else
      if(place->right)
	do_contains(value, place->right);
}

template <typename E>
unsigned int
BST<E>::size()
{
  if(!root)
    return 0;
  else
    {
      Node* place = root;
      return do_size(place);
    }
}

template <typename E>
unsigned int
BST<E>::do_size(Node* place)
{
  unsigned int size = 1;
  size += (place->left) ? do_size(place->left) : 0;
  size += (place-> right) ? do_size(place->right) : 0;
  return size;
}

template <typename E>
E*
BST<E>::contents_as_array()
{
  E* content_array = new E[size()];
  if(!root)
    throw std::runtime_error("there are no contents");
  else
    {
      Node* place = root;  
      do_contents_as_array(content_array, place);
    }
  return content_array;
}

template <typename E>
E*
BST<E>::do_contents_as_array(E* array, Node* place)
{
  if(place->left)
    array = do_contents_as_array(array, place->left);

  *array++ = place->data;
  
  if(place->right)
    array = do_contents_as_array(array, place->right);

  return array;
}

template <typename E>
unsigned int
BST<E>::shortest_branch_length()
{
  if(!root)
    throw std::runtime_error("No root");
  else if(is_leaf(root))
    return 1;
  else
    {
      Node* place = root;
      return  do_shortest_branch_length(place);
    }
}

template <typename E>
unsigned int
BST<E>::do_shortest_branch_length(Node* place)
{
  unsigned int shortest1 = 1;
  unsigned int shortest2 = 1;
  
  shortest1 += (place->left) ? do_shortest_branch_length(place->left) : 0;
  shortest2 += (place-> right) ? do_shortest_branch_length(place->right) : 0;

  return (shortest1<shortest2) ? shortest1 : shortest2;
}
 
 
#endif
```
