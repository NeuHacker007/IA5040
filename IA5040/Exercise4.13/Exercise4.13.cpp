//Exercise 4 - 13: Write a recursive version of the reverse(s) function which reverses a string in place.A couple hints :
//
//-Get the entire input string before calling the reverse() function
//- reverse() definition might look like this : void reverse(char[], int length)  where length is the length of the input
//string(of course there are many ways to write this function, but the implementation using this definition works well)
//- the string should be reversed "in place" meaning you do not create a new variable for the result string but use the string
//which is passed into the function and swap the characters of this string.Since character arrays are passed into functions by memory
//address(not by value) the client caller of the function will see the result when the character values within this string are reversed.

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1024

void reverse(char[], int, int);

int main()
{
	char strs[MAX_STR_LEN]; // declare a character array to holds user inputs
	int c;
	int i = 0;

	// gets the input string
	while ((c = getchar()) != '\n' && c != EOF)
	{
		strs[i++] = c;

	}
	strs[i] = '\0'; // add string termination sign to the character array


	// accept three parameters:
	// 1. character array need to be reversed
	// 2. the swap start position (by default is 0 as the first element in the array)
	// 3. the actual length of the characters array.
	reverse(strs, 0, i - 1);

	// output the reversed character array
	printf("%s", strs);

	// keep console screen holds in case of automatically close after execution.
	getchar();
	return 0;
}

/*
	str[]: is the array need to be reversed;
	lowposition: is start from position 0 which is the bottom of the input array
	highposition: is the top element position in the array;
*/
void reverse(char str[], int lowposition, int highposition) {

	// this is recursive termination condition
	// if lowposition greater than high position
	// the recursive stops.
	if (highposition < lowposition)
	{
		return;
	}

	// each time swap two characters
	// one from top, and one from bottom
	char temp;
	temp = str[lowposition];
	str[lowposition] = str[highposition];
	str[highposition] = temp;

	//recursively call the function to update the character sequence in the array
	reverse(str, ++lowposition, --highposition);

}

