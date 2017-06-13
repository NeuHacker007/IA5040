#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 2014

void reverse(char *p, int length);
int main()
{
	char str[MAX_STR_LEN];

	int c;
	int i = 0;

	// gets the input string
	while ((c = getchar()) != '\n' && c != EOF)
	{
		str[i++] = c;

	}
	str[i] = '\0'; // add string termination sign to the character array


	reverse(str, strlen(str));
	printf("%s\n", str);
	getchar();
	return 0;
}
// char *p :Take the char array's first memory address
// int length : Take the string length.
void reverse(char *firstelementaddr, int length)
{
	// if string is empty return nothing
	if (length <= 0)
		return;
	// declare a pointer take the highest memory address value
	char *lastelementaddr;
	// set this pointer to point the last elements in the array
	lastelementaddr = firstelementaddr + length - 1;

	// swap the lower and higher elements
	int temp;
	temp = *firstelementaddr;
	*firstelementaddr = *lastelementaddr;
	*lastelementaddr = temp;

	// recursively doing this and make the length parameter down to quit condition
	reverse(firstelementaddr + 1, length - 2);
}