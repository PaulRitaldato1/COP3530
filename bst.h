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
