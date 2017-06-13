// Excise3.6.cpp : Defines the entry point for the console application.
/*
Exercise 3-6: Modify the itoa function given on page 64 of the text to include a
3rd parameter to specify the minimum width of the string array. Use the reverse function
on page 62 as is. Use a main() function similar to the one shown below.
Hand in your source code and a screen shot of your output.

*/

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
void itoa(int n, char s[], int width);
void reverse(char s[]);
int main()
{
	char theString[100];
	int theInt = 4539;    // hard code a sample integer here....
	itoa(theInt, theString, 15);  // hardcode your width value - I have set it to 10 here....
	printf("The String Length is %d\n", strlen(theString));
	printf("The character string is %s\n", theString);
	getchar();

}
void itoa(int n, char s[], int width)
{
	// Use the code from the text of pg 64 and add your code to pad the
	//string with blanks.  Use a character like a semi-colon ';' first so
	//you can more easily see your output.

	int i = 0;
	int signal;
	if ((signal = n) < 0)
	{
		// make the number to non negative value
		n = -n;
	}

	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (signal < 0)
	{
		s[i++] = '-';
	}
	//padding the string with specific length
	for ( ; i < width;)
	{
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}



