// Excise1.19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define MAX_LINE_SIZE 2048

void splitLines(char c[]);
void reverseString(char c[]);
int getStringLength(char c[]);
int getInputline(char c[],int actuallength);

int main()
{
	char line[MAX_LINE_SIZE];

	while (getInputline(line,sizeof(line)) > 0)
	{
		splitLines(line);
		reverseString(line);
		printf("%s\n", line);
	}
	getchar();

	return 0;
}

// check each character and
// split whole text to individual
// lines. Each line is a string
void splitLines(char c[]) {
	int i = 0;
	while (c[i] != '\0')
	{
		// if there is a line switching
		// make each line as a string.
		if (c[i] == '\n') {
			c[i] = '\0';
		}
		i++;
	}
}

int getStringLength(char c[]) {
	int i;

	//this will traverse all the characters
	// within a string and get the number of
	// characters in this string.
	for (i = 0; c[i] != '\0'; i++)
	{

	}
	return i;
}

void reverseString(char c[]) {
	char temp;
	int i;
	int j = getStringLength(c) -1;

	for ( i = 0; i < j; i++)
	{
		temp = c[i];
		c[i] = c[j];
		c[j] = temp;
		j--;
	}
}

int getInputline(char line[], int actuallength){

	int c;
	int i;

	// initialize the array with character read from text
	for (i = 0; i < actuallength -1 && ( c = getchar()) != EOF && c != '\n'; i++)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i++] = c; // put \n to the end of string which help following functions to deal with
	}

	//line[i] = '\0'; // put string end sign to the end of the string array

	return i;
}







