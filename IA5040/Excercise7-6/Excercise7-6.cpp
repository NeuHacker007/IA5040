// Excercise7-6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN_LINE 1024
// this function will compare two strings by using the default
// function in string.h
// It takes one line from A file and one line from B file with
// the same line number
void Find_DiffLine(char *lineone, char *linetwo, int num);
int main(int argc, char *argv[])
{
	//declare two file stream pointer to hold the loaded files
	//declare two char array to hold the lines
	FILE *file1, *file2;
	char file1_line[MAX_LEN_LINE], file2_line[MAX_LEN_LINE];

	// open file as read-only mode
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2],"r");

	// make sure the file can be opened normally
	if (NULL == file1 || NULL == file2)
	{
		printf("Error on opening either file %s or file %s\n",argv[1],argv[2]);
	}

	int rownum = 0;
	// Continuously read two files into our program
	// and each time read one line from both file
	while (fgets(file1_line, MAX_LEN_LINE,file1) != NULL
		  && fgets(file2_line, MAX_LEN_LINE, file2) != NULL)
	{
		Find_DiffLine(file1_line, file2_line, rownum);
		break; //if the first differ line is found, then print it out and exit the loop
		rownum++;
	}

	// clean up the memory occupation of two file stream
	fclose(file1);
	fclose(file2);
	return 0;
}

// This function is used to print differ lines
// It takes two strings which represent two lines from two files
// also, it takes the line num for printing purpose
void Find_DiffLine(char *lineone, char *linetwo, int num) {
	// using strcmp to compare the lines from different file
	if (strcmp(lineone,linetwo) != 0)
	{
		// formats the compare results looks like UNIX style
		printf("%d<%s\n%d>%s\n",num,lineone,num,linetwo);
	}
}

