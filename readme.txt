//explain how to build and run your program

//brief description of the pieces of assignment and challenges overcame

//quality and coverage of test cases
//cleanliness of implementation and documentation
//correctness and efficiency


Chanllenges overcame:
	1. Learning about the pointers in C and how to avoid memory leaks by using free() or setting pointer = NULL when pointer is no longer needed. 

	2. learning the follwing functions based on assignment hints:
				=> size_t strlen(char* str) = size excluding \n
				=> int strncmp(char* str1, char* str2 [size_t n])
							byte comparision of first n chars in string to determine which is less(comes before) than other
							0 = equal <0 = str1 is less >0 str2 is less 
				=> char* strdup (char* s) => copy s to new address and return pointer  .  NULL or value