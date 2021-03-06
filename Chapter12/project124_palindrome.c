// Write a program that reads a message, then checks whether it's palindrome
// (the letters in the message are the same from left to right as from right to left)
// Enter a message: He lived as a devil, eh?
// Palindrome
// Enter a message: Madam, I am Adam. 
// Not a palindrome
// Revise the program to use pointers instead of integers to keep track of positions in the array. 
// 
// Simplify Programming Project 2(b) by taking advantage of the fact that an array
// name can be used as a pointer.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MSG_LENG 80

void result (bool );
void read_msg (char [], int );
bool analyze (char []);

int msg_length = 0;

int main (void)
{
	char msg[MSG_LENG];
	
	printf("Enter a message: ");
	read_msg (msg, MSG_LENG);
	result (analyze (msg));
	
	return 0;
}

void result (bool answer)
{
	answer ? printf("Palindrome.\n") : printf("Not a palindrome.\n");
	return ;
}

void read_msg (char msg[], int array_limit)
{
	char *p; 
				
	for ( p = msg; p < msg + array_limit ;) {   //Modifying here. &msg[array_limit]//
		*p = getchar();
		if (isalpha(*p)){
			p++;
			msg_length++;
		}
		if (*p == '\n') break;
	}
	
	return ;
}

bool analyze (char msg[])
{
	char *p, *q;
	
	for (p = msg, q = p + msg_length - 1; p <= q ; p++, q--)
		if (toupper(*p) != toupper(*q)) return false;
	
	return true;
}

	
	
		

