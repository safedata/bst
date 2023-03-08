#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "list.h"

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf(" use as bs filename, filename contains int values");
		return 1;
	}
	List *intvalues = readlistfromfile(argv[1]);
	Node *root = NULL;
	List *currentList = intvalues;
	while (currentList!=NULL) {
		root = addnode(root, currentList->value);
		currentList= currentList->next;
	}
	printnode(root);
	currentList = intvalues;
	while (currentList!=NULL) {
		printf(" find value %d\n %d\n" ,currentList->value, binarysearch(root, currentList->value));
		currentList= currentList->next;
	}
}

List* readlistfromfile(const char * filename) {
    int a;  
    List* list = NULL;
    FILE *file = fopen(filename,"r");
    char charval[10];

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    while (fscanf(file, "%d", &a) != EOF) { // loop until end of file
           if (list == NULL) {
		list = (List*) malloc(sizeof(List));
		list->next = NULL;
		list->value = a;
            } else {
		List *currentlist = list;
		while (currentlist->next != NULL) currentlist = currentlist->next;
		List *nextlist = (List*) malloc(sizeof(List));
		nextlist->next = NULL;
		nextlist->value = a;
		currentlist->next = nextlist;
	    }
	    
      }

    fclose(file);

    return list;
	
}
