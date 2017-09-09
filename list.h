/*Put any struct definitions, typedefs and the above function prototypes in a header file
“list.h”*/
#ifndef LIST_HEAD
#define LIST_HEAD
typedef struct
{
	char* data;
	struct list* next;	

}list;

list* create_list();
int add_to_list(list* ll, char* item);

#endif