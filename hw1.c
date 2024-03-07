#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


static void methods()
{
    // TODO printf all global and weak functions in lib.o
    //      one per line, in alphabetic order
    //      your code should be something like:
    //        printf("some_function\n");
    //        printf("some_other_function\n");
    //      you should have exactly one \n in each printf
    printf("error_handler\n");
    printf("is_invalid\n");
    printf("signature\n");
    printf("usage\n");

     // Not implemented, when you have, remove this line.
}


static void vars()
{
    // TODO printf all global and static variables in lib.o
    //      one per line, in alphabetic order
    //      your code should be something like:
    //        printf("some_variable\n");
    //        printf("some_other_variable\n");
    //      you should have exactly one \n in each printf
    printf("ERRORS\n");
    printf("FULL\n");
    printf("FULL_ERRORS\n");
    printf("MODE\n");
    printf("RESTRICTED\n");
    printf("STATUSCODE\n");
    // assert(0); // Not implemented, when you have, remove this line.
}

// TODO define functions and variables you found in lib.o

void usage();	//Test case 3, called in else if

extern void error_handler();
extern int is_invalid();
extern int signature();
extern int STATUSCODE;
extern int RESTRICTED;
extern int FULL;
extern int MODE;
extern int ERRORS;
extern int FULL_ERRORS;


int main(int argc, char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Program needs at least one argument\n");
        return 1;
    }

    char * arg = argv[1];
    if (!strcmp(arg, "methods")) {
        methods();
    } else if (!strcmp(arg, "vars")) {
        vars();
    } else if (!strcmp(arg, "help")) {
      	usage();
	//assert(0); // NOT IMPLEMENTED remove this line once implemented
    } 
    else {
    	if(is_invalid(arg, strlen(arg))){
		MODE = &FULL;
	}
	int result = signature(arg,strlen(arg));
	if(STATUSCODE != 0){
		int stringLEN = strlen(arg);
		for(int x = 0; x < stringLEN / 2; x++){
			char swap = arg[x];
			arg[x] = arg[stringLEN - 1 - x];
			arg[stringLEN - 1 - x] = swap;
		}
		printf("%s", arg);
	}
	else{
		printf("%d", result);
	}
    }
    return 0;	
    ////assert(0); // NOT IMPLEMENTED remove this line once implemented
}

