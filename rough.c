#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//each node is created dyanamically
struct node{
	int data;
	struct node* next;
};

//returns node* variable for head of list. 
struct node* buildOneTwoThree(){
		struct node* head = NULL;
		struct node* second = NULL;
		struct node* third = NULL;
		
		//allocate three heaps in memory
		head = malloc(sizeof(struct node));
		second = malloc(sizeof(struct node));
		third = malloc(sizeof(struct node));

		//instert the values in the list
		head->data = 1;
		head->next = second;

		second->data = 2;
		second->next = third;


		third->data=3;

		return head;
}	


//given a linked list header pointer, return the number of nodes in the lost


void insertHead(struct node* head, struct node){
	
}

int LengthList(struct node* head){
		struct node* current = head;
		int count = 0;

		while(current!=NULL){
			count++;
			current = current->next;
		}

		return count;

}

int main()
{

	struct node* mypointer = buildOneTwoThree();

	int len = 0;
	free(mypointer->next->next->next);

	struct node new_node;

	insertHead(mypointer, node);

	return(0);
}