/*Put any struct definitions, typedefs and the above function prototypes in a header file
“list.h”*/
#ifndef LIST_H
#define LIST_H

typedef struct node node;
typedef struct list list;

struct node{
	char * data;
	node* next;
};

struct list{
	node* head;
};

//allocates and initialises a new list
   //possible returns NULL or list*
list* create_list();

/*adds new item to the start of the list. 
  Allocates a new buffes and copies string from item
	return 0 if successful and non zero if no successful*/

	//possible returns 10(error) or 0 (success)
int add_to_list(list* ll, char* item);


/* removes string frm the front of the list and returns pointer to it.
caller is expected to free string returned*/

	//possible returns NULL(for empty list) and char* (if successful)
char* remove_from_list(list* ll);

//
void print_list(list* ll);

//clear the entire list while deallocating nodes and keeping the head still valid
void flush_list(list* ll);


//deallocates all nodes and the list itself

void free_list(list* ll);

#endif 