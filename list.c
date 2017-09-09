/* Allocates and initializes a new list */
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//Allocates and initialises a new list
list* create_list( ){
		list* head = malloc(sizeof(list));
		head -> next = NULL;
		return head;	
};

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item){

}

int main(){


	return 0;
}