// Simplify Programming project 1(b) by taking advantage of the fact that
// an array name can be used as a pointer. 

#include <stdio.h>

#define MSG_LEN 80

int main (void)
{
	char msg[MSG_LEN], *p;
	
	printf("Enter a message: ");
	for ( p = msg; p < msg + MSG_LEN; p++) {
		*p = getchar();
		if ( *p == '\n')
			break;
	}
	
	printf("Reversal is: ");
	for (p--; p >= msg; p--)
		putchar(*p);
	putchar('\n');
	
	return 0;
}
	
