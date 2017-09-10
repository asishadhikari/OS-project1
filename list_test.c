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
	if(flag==0) printf("createlist() Test Successful!! for value %i \n",n);
	else if(flag==1) printf("createlist() Test Unsuccessful! for value %i\n",n);
	else printf("createlist() Undefined case!\n");
}

void add_to_list_test(int n){
	int insertion_successful_flag = 10;
	list* myList = create_list();
	
	insertion_successful_flag = add_to_list(ll, "Ashish");
	if(insertion_successful_flag==0) printf("Insertion successful in empty list\n",n);
	else if(insertion_successful_flag!=0) printf("Insertion usuccessful in empty list\n",n);


	for (int i = 0; i< n; i++){
		//keep updating if the add_to_list was successful or not
		insertion_successful_flag = add_to_list(myList,"Ashish");
	}

	if(insertion_successful_flag==0) printf("Insertion for %i values successful\n",n);
	else if(insertion_successful_flag!=0) printf("Insertion for %i values usuccessful, something wrong!\n",n);
  
  free(myList);
  myList=NULL;






}








int main(){
	//pass n into complete_create_list_test(n) to find if request to create_list() fails for any i within 0<i<n 
		complete_create_list_test(2);
		complete_create_list_test(2000);
		complete_create_list_test(200000);
		complete_create_list_test(200000000);

		add_to_list_test(20);

	
	return 0;
}