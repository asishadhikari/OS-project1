//Test goes here
//try various combinations of funcitons. 
// check return value on function that can fail
#include <stdlib.h>
#include <stdio.h>
#include "list.h"


//very inefficient as a lot of memory leaks, Thus testing if the OS can handle a high pressure
void complete_create_list_test(int n){
	list* ll;
	int flag = 0;
	for (int i =0; i<n; i++){
			ll = create_list();
			if (ll==NULL) {
				flag = 1;
				break;
			}
	}
	if(flag==0) printf("createlist() Test Successful!! for  %i nodes\n",n);
	else if(flag==1) printf("createlist() Test Unsuccessful! for %i nodes\n",n);
	else printf("createlist() Undefined case!\n");
printf("\n\t\t#############################################\n\n");
}

void add_to_list_test(int n){
	int insertion_successful_flag = 10;
	list* myList = create_list();
	//insertion to empty list
	//add_to_list returns if successful
	insertion_successful_flag = add_to_list(myList, "GrandpaRick");
	if(insertion_successful_flag==0){
		printf("Insertion successful in empty list\n");
	} 
	else if(insertion_successful_flag!=0){
	 printf("Insertion usuccessful in empty list\n");
  }

	//for given n, find if function fails for any one operation
	for (int i = 0; i< n; i++){
		//keep updating if the add_to_list was successful or not
		insertion_successful_flag = add_to_list(myList,"GrandpaRick");
	}

	if(insertion_successful_flag==0) printf("Insertion for %i values successful\n",n);
	else if(insertion_successful_flag!=0) printf("Insertion for %i values usuccessful, something wrong!\n",n);
  //too many memory leaks in code but no way to get rid of them without 
  free(myList);
  myList=NULL;
  printf("\n\t\t#############################################\n\n");
}


void remove_from_list_test(int n){
	list* myList = create_list();
	char* expected = "GrandpaRick";

	//remove from empty list
	if(n==0){
		char* test = remove_from_list(myList);
		if(test==NULL) printf("Expected value=NULL returned value == NULL Test successful for empty list remove\n");
		else printf("Test Failed!! Non NULL returned on remove from empty list\n");
	}

	else if(n==1){
		add_to_list(myList,"GrandpaRick");
		char* returned = remove_from_list(myList);

		//if returned c string and head points to NULL, test successful
		if((*expected==*returned)&& (myList->head==NULL))
			printf("remove_from_list on one node successful!! Head points to null and returned value matches!\n"); 
		else printf("Something wrong with removal from on node list!!\n");
	}
	//if more than one nodes in list
	else if(n>1){
		for (int i = 0; i<n; i++){
			add_to_list(myList,"GrandpaRick");
		}

		char* returned = remove_from_list(myList);
		if(*expected==*returned)
			printf("remove_from_list on large(>1 nodes) list successful!! Returned and expected values match!\n"); 
 
	}
	printf("\n\t\t#############################################\n\n");
}


void print_list_test(){
	list* myList = create_list();

	//print empty list
	printf("\n\nPrinting Empty list\nExpected Output:\nList Empty!");
	printf("\n\nActual Output:\n");
	print_list(myList);

  //print one node list
  add_to_list(myList,"GrandpaRick");
	printf("\n\nPrinting list wih 1 node\nExpected Output:\nGrandpaRick");
	printf("\n\nActual Output:\n");
	print_list(myList);
 
  //print 10 node list:
	for(int i = 0; i< 9; i++){
		add_to_list(myList,"GrandpaRick");
	}


	printf("\n\nPrinting list wih 10 node\nExpected Output:\n");
	for (int i = 0; i<10; i++){
		printf("GrandpaRick\n");
	}
	printf("\n\nActual Output:\n");
	print_list(myList);
	printf("\n\t\t#############################################\n\n");
}

  
void flush_list_test(){
	//testing with 0, 1 and 200 nodes
	list* myList = create_list();
	list* myList1 = create_list(); 
	list* myList200 = create_list();
	//flush empty list
	flush_list(myList);
	if(myList->head==NULL) printf("(0 node) List is valid and list->head is NUll. Test successful\n");
	else printf("Test Unsuccessful head is not null\n");
	free_list(myList);  //prevent memory leaks

	//flush single node list
	add_to_list(myList1,"GrandpaRick");
	flush_list(myList1);
	//successfully flushed only if head points to NULL
	if(myList1->head==NULL) printf("(1 node) List is valid and list->head is NUll. Test successful\n");
	else printf("Test Unsuccessful head is not null\n");
	free_list(myList1);
	
	//flush list with 200 nodes
	for(int i = 0; i<20; i++){
		add_to_list(myList200, "GrandpaRick");
	}
	flush_list(myList200);
	//successfully flushed only if head points to NULL
	if(myList200->head==NULL) printf("(100) List is valid and list->head is NUll. Test successful\n");
	else printf("Test Unsuccessful head is not null\n");
	free_list(myList200);
	printf("\n\t\t#############################################\n\n");
}

void free_list_test(){
	//testing with 0, 1  and 200 nodes
	list* myList = create_list();
	list* myList1 = create_list(); 
	list* myList200 = create_list();

	//free empty list
	free_list(myList);
	if(myList->head==NULL)printf("\nTest Successful! List and its nodes were successfully deleted!\n");
	else printf("\nTest not successful, the list still seems to point somewhere!\n");
  
	//free 1 node list
	add_to_list(myList1,"GrandpaRick");
	free_list(myList1);
	if(myList1->head==NULL)printf("\nTest Successful! List and its nodes were successfully deleted!\n");
	else printf("\nTest not successful, the list still seems to point somewhere!\n");
  

  //free list with 200 nodes
  for(int i = 0; i<200; i++){
  	add_to_list(myList200,"GrandpaRick");
  }
  free_list(myList200);
  if(myList200->head==NULL)printf("\nTest Successful! List and its nodes were successfully deleted!\n");
	else printf("\nTest not successful, the list still seems to point somewhere!\n");


}



int main(){
	//pass n into complete_create_list_test(n) to find if request to create_list() fails for any i within 0<i<n 

		complete_create_list_test(200000);
		//complete_create_list_test(200000000);

		add_to_list_test(20000);
		//add_to_list_test(2000000000);

		remove_from_list_test(0);
		remove_from_list_test(1);
		remove_from_list_test(100);
		//remove_from_list_test(1000000000000);

		//tests list with 0, 1 and more(10) nodes.
		print_list_test();
		

		//flushes and tests results for list with 0, 1 and more(20) nodes
		flush_list_test();

		//free list with 0, 1 and 200 nodes
		free_list_test();



	return 0;
}