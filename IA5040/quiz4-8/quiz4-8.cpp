// quiz4-8.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int getmax(int*, int);
int main()
{
	int size, c;
	int *elements;
	int *copy_elements;
	printf("Enter the number of elements to be entered:\n");
	scanf_s("%d", &size);

	printf("Enter %d integers\n", size);
	elements = (int*)malloc(size * sizeof(int));
	copy_elements = elements;

	for (c = 0; c < size; c++)
		scanf_s("%d", elements++);

	int max = getmax(copy_elements, size);
	printf("Maximum: %d\n", max);
	
	free(copy_elements);


	return 0;
}
int getmax(int* elements, int size)
{
	// get the first element of the pointer array
	int *max = elements;

	// loop the entire array and compare each
	// elements with its next element
	for (int i = 0; i < size; i++)
	{
		// if current max is larger than the next element
		// the max is the current max
		// or if current max is smaller than the next element
		// assign next element to max
		max = (*max > *(elements + i)) ? max : (elements + i);
	}
	return *max;

}