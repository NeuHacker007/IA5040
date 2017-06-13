// Excise1.19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define MAX_LINE_SIZE 2048

void splitLines(char *c);
void reverse(char *p, int length);
int getStringLength(char *c);
int getInputline(char *c, int actuallength);

int main()
{
	char line[MAX_LINE_SIZE];

	while (getInputline(line, sizeof(line)) > 0)
	{
		splitLines(line);
		reverse(line, getStringLength(line));
		printf("%s\n", line);
	}
	getchar();

	return 0;
}

// check each character and
// split whole text to individual
// lines. Each line is a string
void splitLines(char *c) {
	int i = 0;
	while (*(c + i) != '\0')
	{
		// if there is a line switching
		// make each line as a string.
		if (*(c + i) == '\n') {
			*(c + i) = '\0';
		}
		i++;
	}
}

int getStringLength(char *c) {
	int i;

	//this will traverse all the characters
	// within a string and get the number of
	// characters in this string.
	for (i = 0; *(c + i) != '\0'; i++)
	{

	}
	return i;
}

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

int getInputline(char *line, int actuallength) {

	int c;
	int i;

	// initialize the array with character read from text
	for (i = 0; i < actuallength - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		*(line + i) = c;
	}

	if (c == '\n')
	{
		*(line +(i)) = c; // put \n to the end of string which help following functions to deal with
	}

	//line[i] = '\0'; // put string end sign to the end of the string array

	return i;
}







