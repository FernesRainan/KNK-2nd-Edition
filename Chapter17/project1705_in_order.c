// Write a program that sorts a series of words entered by the user:
// Enter word: foo
// Enter word: bar
// Enter word: baz
// Enter word: quux
// Enter word:
//
// In sorted order: bar baz foo quux
//
// Assume that each word is no more than 20 characters long. Stop reading when the user
// enters an empty word (i.e., presses Enter without entering a word). Store each word in a 
// dynamically allocated string using an array of pointers to keep track of the strings, as in the
// remind2.c program (Section 17.2). After all words have been read, sort the array (using 
// any sorting technique) and then use a loop to print the words in sorted order. Hint: Use the
// read_line function to read each word, as in remind2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50  // maximum number of WORDS
#define WORD_LEN 20   // max length of word

int read_line (char str[], int n);

int main (void)
{
	char *reminders[MAX_WORDS];
	char msg_str[WORD_LEN+1];
	int i, j, word_num = 0;
	
	for (i = 0; ;i++) 
	{
		if (word_num == MAX_WORDS){
			printf("-- No space left --\n");
			break;
		}
		
		printf("Enter word: ");
		
		if (!(read_line(msg_str, WORD_LEN))) 
			break;
			                                                   
		reminders[i] = malloc(strlen(msg_str) + 1);    
		if (reminders[i] == NULL){                        
			printf("-- No space left --\n");                 
			break;                                           
		}                                                  
		strcpy(reminders[i], msg_str);
		word_num++;
	}
	
	for (i = 1; i < word_num; i++) {
		for (j = 1; j < word_num; j++){
			if(strcmp(reminders[j-1], reminders[j]) > 0) {
				strcpy(msg_str, reminders[j-1]);
				strcpy(reminders[j-1], reminders[j]);
				strcpy(reminders[j], msg_str);
			}
		}
	}
	
	printf("\nIn sorted order: ");
	for ( i = 0; i < word_num; i++)
		printf(" %s", reminders[i]);
	
	putchar('\n');
		
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
