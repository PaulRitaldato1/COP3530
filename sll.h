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
