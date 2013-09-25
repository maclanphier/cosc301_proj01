/*
 *
 * Brett Rojec
 * Mac Lanphier
 * 9/17/13
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "list.h"




int *tokenify(const char *str) { 		//FINISHED! 	RUNS PROPERLY!
	const char* sep = " \t\n";
	char* tmp;
	char* word;
	char* s = strdup(str);
	//int charCount = 0;
	int pointCount = 1;
	for(word = strtok_r(s,sep,&tmp); word != NULL; word = strtok_r(NULL,sep,&tmp)){
		int i;		
		int test = 1;
		for(i = 0; i < strlen(word); i++){ //Check if word is an integer
			if(isdigit(word[i]) == 0) {
				test = 0;
			}
		}
		//charCount += strlen(word);
		//charCount ++;
		if(test == 1){ //If word is an integer, make room for it
			pointCount ++;
		}
	}
	free(s);
	int* pointArray = (int*) malloc(pointCount*sizeof(int));
	pointArray[0] = (int)malloc(sizeof(int));
	int pointInd = 1;
	int intCount = 0;
	s = strdup(str);
	for(word = strtok_r(s,sep,&tmp); word != NULL; word = strtok_r(NULL,sep,&tmp)){
		int i;		
		int test = 1;
		for(i = 0; i < strlen(word); i++){ //Check if word is an integer
			if(isdigit(word[i]) == 0) {
				test = 0;
			}
		}
		if(test == 1){ //If word is an integer, add it to the list
			//printf("\nFound an int!");
			int num = atoi(word);
			pointArray[pointInd] = (int) malloc(sizeof(int));
			pointArray[pointInd] = num;
			pointInd ++;
			intCount ++;
		}
	}
	pointArray[0] = intCount;
	free(s);
	return pointArray;
}


struct node** reader(FILE* datafile){		//UNFINISHED
	char* data = NULL;
	fgets(data, 255, datafile);
	struct node** int_list = (struct node**)malloc(sizeof(struct node*));
	int_list[0] = NULL;
	//int nodeCount = 0;
	while(data != NULL){
		int* list = tokenify(data);
		int i = 1;
		for(;i<=list[0];i++){
			list_insert(list[i],int_list);
		}
		fgets(data,255,datafile);
	}
	return int_list;
}






void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}


int main(int argc, char **argv) {
    FILE *datafile = NULL;
	//testing here
	//char str[] = "1 45 281 bob oblah's 25th law blog";
	//int* token = tokenify(str);



	//end test

    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */ 
            /* just equate stdin with our datafile */
            datafile = stdin;        
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            /* more than two arguments?  throw hands up in resignation */
            usage(argv[0]);
    }

    /* 
     * you should be able to just read from datafile regardless 
     * whether it's stdin or a "real" file.
     */

	struct node** intList = reader(datafile);
	list_print(*intList);


	

	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	printf("System time: %06lfs\n",usage.ru_stime.tv_usec);
	printf("User time: %06lfs\n",usage.ru_utime.tv_usec);
    fclose(datafile);

    return 0;
}

