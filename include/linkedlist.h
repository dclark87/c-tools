// linkedlist.h
//
// Author: Daniel Clark

// Define guard
#ifndef CTOOLS_LINKEDLIST_H_
#define CTOOLS_LINKEDLIST_H_

// Includes
#include <stdio.h>

// Declare node as struct type
struct Node {
    int val;
    struct Node * next;
};

// Declare NodeClass with typedef on node
typedef struct _Node Node;
struct _Node {
    int val;
    Node * next;
};

// Declaring typdef Node struct inline
typedef struct Node {
    int val;
    Node * next;
};


#endif //CTOOLS_LINKEDLIST_H
