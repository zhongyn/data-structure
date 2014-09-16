#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashMap.h"


void keyPrint(void* k)
{
  char *key = (char *)k;
  printf("%s", key);

}


void valPrint(void* v)
{
  int *val = (int *)v;
  printf("%d", *val);
}

int myCompare(void *s1, void *s2)
{
  char *key1 = (char *)s1;
  char *key2 = (char *)s2;

  return (strcmp(key1, key2));
}

/* Better solution: Pass the hashfunciton in to the hashMap functions with a function pointer */

/*the first hashing function you can use*/
int hash1(void *key)
{
  char *str = (char *)key;
  
  int i;
  int r = 0;
  for (i = 0; str[i] != '\0'; i++)
    r += str[i];
  return r;
}

/*the second hashing function you can use*/
int hash2(void * key)
{
  char *str = (char *)key;
  
  int i;
  int r = 0;
  for (i = 0; str[i] != '\0'; i++)
    r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
  return r;
}

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;	
	int tableSize = 10;
	clock_t timer;
	FILE *fileptr;	
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.
     
     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input1.txt"; /*specify your input text file here*/
    
    printf("opening file: %s\n", filename);
    
	timer = clock();
	
	hashTable = createMap(tableSize);	   
	fileptr = fopen(filename, "r+");
	void *word = getWord(fileptr);
	int initV = 1;
	void *v;

    /*... concordance code goes here ...*/
    while(word != NULL)
    {
    	v = atMap(hashTable, word, myCompare, hash2);
    	if (v != NULL)
    	{
    		(*(int*)v)++;
    	} else {
    		v = malloc(sizeof(int));
    		v = (void *)&initV;
    		insertMap(hashTable, word, v, myCompare, hash2);
		printf("success => %s\n", word);
    	}

    	word = getWord(fileptr);   	
    }
		
	/*... concordance code ends here ...*/

	timer = clock() - timer;
	printMap(hashTable, keyPrint, valPrint);
	printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
	printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));
	
	printf("Deleting keys\n");
	
	removeKey(hashTable, "and", myCompare, hash2);
	removeKey(hashTable, "me", myCompare, hash2);
	removeKey(hashTable, "the", myCompare, hash2);
	printMap(hashTable, keyPrint, valPrint);
		
	deleteMap(hashTable);
	printf("\nDeleted the table\n");   
	return 0;
}

void printValue(void* v) {
	printf("Value:%d", *(int *)v);
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
