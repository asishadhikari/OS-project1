/*Put any struct definitions, typedefs and the above function prototypes in a header file
“list.h”*/
#ifndef LIST_HEAD
#define LIST_HEAD
typedef struct list list;
struct list{
	//store cstring
	char* data;
	struct list* next;	

};

list* create_list();
int add_to_list(list* ll, char* item);
char* remove_from_list(list* ll);

#endif