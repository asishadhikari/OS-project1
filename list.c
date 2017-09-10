/* Allocates and initializes a new list */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"


list* create_list(){
	list* myList = (list*) malloc (sizeof(list));
	myList->head = NULL;
	return myList;  
}


int add_to_list(list* ll, char* item){
	int flag = 10;
	//if the list if empty and has been just initialised;
	if (ll->head==NULL){
		
		node* newNode = (node*) malloc(sizeof(node));
		newNode->data = (char*) malloc(sizeof(item));
		strcpy(newNode->data, item);
		//next node for empty list is NULL
		
		newNode->next = NULL;
		ll->head = newNode;
		//prevent illegal reference
		newNode = NULL;
	}

	else if (ll->head !=NULL){
		node* newNode = (node*)malloc(sizeof(node));
		newNode -> data = (char*)malloc(sizeof(item));
		strcpy(newNode->data,item);
		newNode->next = ll->head;
		ll->head = newNode;
		//prevent illegal reference in future
		newNode = NULL;
	//if allocation for node failed and item was not inserted
	}

	if (ll->head == NULL) flag = 10;			
	
	return flag;
}



char* remove_from_list(list* ll){
	//if list is empty return NULL
	char* tempChar;
	if(ll->head==NULL) tempChar = NULL;

	else if (ll->head!=NULL){
		tempChar = ll->head->data;
		node* tempPtr = ll->head->next;
		//prevent memory leak
		free(ll->head);
		ll->head = tempPtr;
		//prevent illegal access
		tempPtr=NULL;
  }
  return tempChar; 		 
}

void print_list(list* ll){
	if (ll->head == NULL) printf("List Empty!\n");
	
	else if(ll->head!=NULL){
		node* curNode = ll->head;
		do{
					printf("%s\n", curNode->data);
					curNode = curNode->next;
		} while (curNode!=NULL);		
	}
}

void flush_list(list* ll){
	//only applicable if the list is non empty
	if(ll->head!=NULL){
		while(ll->head!=NULL){
			//remove from list also deallocates the nodes
			char* temp = remove_from_list(ll);
			free(temp);
			temp = NULL;
		}

	}

}

//completely erase trace of list ll including memory allocation of list and the data
void free_list(list* ll){
	flush_list(ll);
	free(ll);
	ll = NULL;
}

int main(){
	


	return 0;
}


