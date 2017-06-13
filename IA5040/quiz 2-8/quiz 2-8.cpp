// quiz 2-8.cpp : Defines the entry point for the console application.
/*
Prints a message to the screen asking the user to input an integer which corresponds to a month in the year(1=Jan,2=Feb,3=March,...12=Dec)
Accepts the user's input and stores this input in a variable
Calls a function named season(int month) which takes the value input by the user as a parameter
Accept new input from the user until the user inputs the value 0. Then prints an exit message and the program terminates.

Your task is to write the function season(int month).  This function will:

Print the name of the season associated with the given month
Winter is months 12,1,2
Spring is months 3,4,5
Summer is months 6,7,8
Fall is months 9,10,11
Provide a default error statement to print for values sent to the function which are less than 1 or greater than 12
Utilize a switch() statement to code this functionality
Include appropriate documentation

*/

#include "stdafx.h"
#include <stdio.h>


#include <stdio.h>
void season(int month);
void main()
{
	int c;
	printf("\nType in a number(type 0 to exit)for your month:");
	scanf_s("%d", &c);
	while (c != 0)
	{
		season(c);
		printf("\nType in a number(type 0 to exit)for your month:");
		scanf_s("%d", &c);
	}
	printf("\nNormal Exit.\n");
}
void season(int month)
{
	switch (month)
	{   // print winter month
		case 12: case 1: case 2:
			printf("Winter!\n"); break;
		//print spring month
		case 3: case 4: case 5:
			printf("Spring!\n"); break;
		//print Summer month
		case 6 : case 7: case 8:
			printf("Summer!\n"); break;
		//print Fall month;
		case 9: case 10: case 11:
			printf("Fall!\n"); break;
		default:
			printf("Error! Please enter the number range from 1 - 12!\n");
			break;
	}
}

