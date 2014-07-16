/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

int isUpperCase(char ch)
{
    return 'A'<=ch && ch<='Z';
}

int isLowerCase(char ch)
{
    return 'a'<=ch && ch<='z';
}

void studly(char* word){
     /*Convert to studly caps*/
    int even = 1;
	while (*word != '\0')
	{   
        if (even)
        {
            if (isLowerCase(*word)) *word = toUpperCase(*word);
            even = 0;            
        } else 
        {
            if (isUpperCase(*word)) *word = toLowerCase(*word);
            even = 1;
        }
        word++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
    char str[100];
    scanf("%s", str);
    /*Call studly*/
    studly(str);
    /*Print the new word*/
    printf("%s\n", str);
    return 0;
}
