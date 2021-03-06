// Write the following function:
// void build_index_url (const char *domain, char *index_url);
// Keep the function as simple as possible by having it use the 'strcat and strcpy' functions. 

#include <stdio.h>
#include <string.h>

#define URL_LEN 255

void build_index_url (const char *domain, char *index_url)
{
	strcpy (index_url, "http://www.");
	strcat (index_url, domain);
	strcat (index_url, "/index.html");
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <domain>\n", argv[0]);
		return 1;
	}
	
	char url[URL_LEN];
	
	build_index_url (argv[1], url);
	
	printf("%s\n", url);
	
	return 0;
}
