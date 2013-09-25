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

#include "list.h"




char **tokenify(const char *str) {
	const char* sep = " \t\n";
	char* tmp;
	char* word;
	char* s = strdup(str);
	int charCount = 0;
	int pointCount = 1;
	for(word = strtok_r(s,sep,&tmp); word != NULL; word = strtok_r(NULL,sep,&tmp)){
		charCount += strlen(word);
		charCount ++;
		pointCount ++;
	}
	free(s);
	char** pointArray = (char**) malloc(pointCount*sizeof(char*));
	int pointInd = 0;
	s = strdup(str);
	for(word = strtok_r(s,sep,&tmp); word != NULL; word = strtok_r(NULL,sep,&tmp)){
		pointArray[pointInd] = strdup(word);
		pointInd ++;
	}
	pointArray[pointInd] = NULL;
	free(s);
	return pointArray;


}


void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}


int main(int argc, char **argv) {
    FILE *datafile = NULL;

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

	char* data;
	while(data = fgets(data, 255, datafile)!=NULL){
		
	}


    fclose(datafile);
    return 0;
}

