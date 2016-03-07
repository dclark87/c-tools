/* linkedlist.h
 *
 * Author: Daniel Clark, 2016
 */

// Define guard
#ifndef CTOOLS_LINKEDLIST_H_
#define CTOOLS_LINKEDLIST_H_

// Includes
#include <stdio.h>

// Declare _Node struct tag (incomplete) for Node alias
typedef struct _Node Node;
// Complete _Node struct definition
struct _Node{
    int val;
    Node * next;
};


// Declaring typdef List struct inline
typedef struct {
    int list_length;
    Node * head;
} List;


// Create list function
void create_list(List * list, int list_length);


// Insert node function
void insert_node(List * list, int val);



#endif // CTOOLS_LINKEDLIST_H
