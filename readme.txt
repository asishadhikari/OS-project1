This document highlights the different challenges and learning experience provided this project. 


1. how to build and run the program:
		<> run the makefile in the directory as make mymake
					-> this should create and executable named list_test2
		<> run the executable as "./list_test2" to see the results of 
				various tests that are written in list_test.c
					-> function implementations are done in list.c



Chanllenges overcame:
	1. Learning about the pointers in C and how to avoid memory leaks by using free() or setting pointer = NULL when pointer is no longer needed. 

	2. learning the follwing functions based on assignment hints:
				=> size_t strlen(char* str) = size excluding \n
				=> int strncmp(char* str1, char* str2 [size_t n])
							byte comparision of first n chars in string to determine which is less(comes before) than other
							0 = equal <0 = str1 is less >0 str2 is less 
				=> char* strdup (char* s) => copy s to new address and return pointer  .  NULL or value

	3. Refreshing on Linked List concepts. Since implementing linked lists in C is very pointer intensive, I found out that making diagrams depicting exact pointer pointee locations (e.g. data with a node is also stored in a separate memory block) made developing an algorithm much easier. 

	4. Being very careful so as not prevent illegal access of pointers (e.g. a temproray pointer that was only supposed to be usd temproraily) by setting them to NULL once not needed. Also, preventing memory leaks by getting rid of unnecessary heap variables was a very interesting experience.  

	5. In the test code, memory leak was required to test how the program performed under limited constraints. All tests worked well for small number of nodes, however, as memory leak was not addressed in all tests, (e.g. in for loop of add_to_list(list*,char*)) the program seemed to be "Killed" by OS for higher memory requirements.

  6. It took me a while to realise that the linked list variable itself (that points to the head) is not a heap variable and thus cannot be deallocated. However, I realised that and modified my test code to evaluate if(myList->head ==NUll) rather than myList == NULL.