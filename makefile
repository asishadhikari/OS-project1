#makefile for the project . Run in shell as make makefile and this will automatically compile and link the two files list.c and list_tect.c
mymake: list.c list_test.c
	gcc -o list_test2 list.c list_test.c -I./

