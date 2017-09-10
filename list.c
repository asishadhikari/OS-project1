/* Allocates and initializes a new list */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

//Allocates and initialises a new list
list* create_list(){
		list* head = malloc(sizeof(list));
		head -> next = NULL;
		head -> data = NULL;
		return head;	
}

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item){
	//check if no loaded nodes exist in list
	int flag = 22;
	if((ll->data)==NULL){
		ll->data = malloc(sizeof(item));
		strcpy(ll->data,item);
		//change value of flag if item successfully copied
		
	}
	//if the list already contains node with data
	else if((ll->data)!=NULL){
		list* newNode = malloc(sizeof(list));
		//change the next pointer to previous head effectively inserting
		newNode->next = ll;
		newNode->data = malloc(sizeof(item));
		strcpy(newNode->data, item);
		ll = newNode;
		//prevent illegal access
		newNode = NULL;

	}
if(*(ll->data) == *item) flag = 0;		
return flag;
}

/*removes the string frmo the front of the list and reutrns the pointer to it.
Caller is expected to free string returned when done with it*/
//NOTE READ THIS ^^^^
char* remove_from_list(list* ll){
	char* ret;
	//if empty list
	if(ll->data==NULL)  ret=NULL;
	
	else if ((ll->data)!=NULL) {
		
		ret = ll-> data;
		list* newHead= ll->next;
		free(ll);
		ll = newHead;
	}
	
	//undefined cases
	else ret=NULL;
	return ret;

}

int main(){

	list* myList = create_list();
	char* str = "Ashish";
	int flag = add_to_list(myList,str);
	remove_from_list(myList);
	add_to_list(myList,str);





	return 0;
}