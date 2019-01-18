# Linked Lists / Stacks / Queues / Recursion
These are the first set of data structures you will be introduced to. The implementations shown here will be simple but they can be expanded.

## Linked Lists
Linked lists are a data structure used to store data. This is a pretty broad statement, but they essentially perform the same functions as an array but with some pros. and cons.

The easiest way for me to explain their usage, would be to explain the differences between a linked list and an array.

### Arrays vs Linked Lists
Linked Lists | Arrays
--- | ---
Not in continuous memory | In contiguous memory
Can be any size (given OS and hardware limitations) and resize | Fixed size in memory
Must iterate through to find a given element (O(n) access time) | Direct indexing (O(1) access time)


### Singly Linked Lists (SLL)
This is the first type of list that will be talked about. A singly linked list consists of nodes, connected by pointers. A singly linked list is only connected "one way" with each node in the list pointing to the next 
