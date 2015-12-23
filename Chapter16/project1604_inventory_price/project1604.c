// Modify the inventory.c program of Section 16.3 by adding a price member to the
// part structure. The insert function should ask the user for the price of a new item. The
// search and print functions should display the price. Add a new command that allows
// the user to change the price of a part. 

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	float price;
} inventory[MAX_PARTS];

int num_parts = 0; // number of parts currently stored 

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void price_update(void); // project1604. new function to change the price of a part. 
void print(void);

// quick sort algorithm 
void quicksort (struct part a[], int low, int high);
int split (struct part a[], int low, int high);

// main: Prompts the user to enter an operation code, 
//       then calls a function to perform the requested
//       action. Repeats until the user enters the 
//       command 'q'. Prints an error message if the user
//       enters an illegal code. 

int main (void)
{
	char code;
	
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')  //skips to end of line
		;
		switch (code) {
			case 'i' : insert();
				break;
			case 's' : search();
				break;
			case 'u' : update();
				break;
			case 'v' : price_update();
				break;
			case 'p' : print();
				break;
			case 'q' : return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

// find_part: Looks up a part number in the inventory
//            array. Returns the array index if the part
//            number is found; otherwise, returns -1.

int find_part(int number)
{
	int i;
	
	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

// insert: Prompts the user for information about a new
//         part and then inserts the part into the
//         database. Prints an error message and returns
//         prematurely if the part already exists or the
//         database is full

void insert (void)
{
	int part_number;
	
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return ;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	if (find_part(part_number) >= 0) {
		printf("Part already exists. \n");
		return ;
	}
	
	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line (inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	printf("Enter price of the product: $");
	scanf("%f", &inventory[num_parts].price);
	num_parts++;
}

// search: Prompts the user to enter a part number, then
//         looks up the part in the database. If the part
//         exists, prints the name and quantity on hand;
//         if not, prints an error message.

void search (void)
{
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
		printf("The price is : %.2f\n", inventory[i].price);
	} else
		printf("Part not found.\n");
}

// update: Prompts the user to enter a part number. 
//         Prints an error message if the part doesn't
//         exist; otherwise, prompts the user to enter
//         change in quantity on hand and updates the
//         database. 

void update(void)
{
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else
		printf("Part not found.\n");
}

// price_update: Prompts the user to enter a part number. 
//         Prints an error message if the part doesn't
//         exist; otherwise, prompts the user to enter
//         change the price of a part on hand and 
//         updates the database. 

void price_update(void)
{
	int i, number;
	float change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change the price of a part: ");
		scanf("%f", &change);
		inventory[i].price += change;
	} else
		printf("Part not found.\n");
}

// print: Prints a listing of all parts in the database, 
//        showing the part number, part name, and
//        quantity on hand. Parts anre printed in the 
//        order in which they were entered into the
//        database. 

void print(void)
{
	int i;
	
	printf("Part number   Part Name                   "
	       "Quantity on Hand     Price\n");
	// quick sort part //
	quicksort (inventory, 0, num_parts-1);
	///////////////////////////////////////
	
	for (i = 0; i < num_parts; i++)
		printf("%7d       %-25s%11d             $%.2f\n", inventory[i].number, 
		       inventory[i].name, inventory[i].on_hand, inventory[i].price);
}

void quicksort(struct part a[], int low, int high)
{
	int middle;
	
	if (low >= high) return;
	
	middle = split(a, low, high);
	quicksort(a, low, middle -1);
	quicksort(a, middle+1, high);
}

int split (struct part a[], int low, int high)
{
	struct part part_element = a[low] ;
		
	for (;;) {
		while (low < high && part_element.number <= a[high].number)
			high--;
		if (low >= high) break;
		a[low++] = a[high];
		
		while (low < high && a[low].number <= part_element.number)
			low++;
		if (low >= high) break;
		a[high--] = a[low];
	}
	
	a[high] = part_element;
	return high;
}

