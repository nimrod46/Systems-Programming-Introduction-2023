#ifndef LINKEDLIST_h
#define LINKEDLIST_h

typedef void* Element;
typedef struct LinkedList* LinkedList;

// Given a function for cloning, and for freeing an element, returns a handle
// To an empty linked list.
LinkedList LLCreate(Element (*clone_func)(Element),
                    void (*free_func)(Element));

// Destroys a list
void LLDestroy(LinkedList ll);

// Returns the number of elements in a list
unsigned int LLSize(LinkedList ll);

// Adds an element at location index (between 0 to LLSize()).
// Use index=0 to insert at the beginning of the list, index=1 to insert between
// the first and second elements, and index=LLSize() to insert after the last
// element.
void LLAdd(LinkedList ll, unsigned int index, const Element element);

// Remove and return an element from the list (index between 0 to LLSize-1)
Element LLRemove(LinkedList ll, unsigned int index);

#endif
