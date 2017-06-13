// quiz5-8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	char* value;
	int count;
	struct node *nextnode;
	struct node *previousnode;
};

int main()
{
    return 0;
}

struct node* addNode(char word[], node *head)
{
	node *newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL) {
		fprintf(stderr, "Unable to allocate memory for new node\n");
		exit(-1);
	}
	newnode->value = word;
	newnode->nextnode = NULL; // init to NULL for now
	newnode->previousnode = NULL; // init to NULL for now
	if (head->nextnode == NULL) { // check for first insertion
		head->nextnode = newnode;
		printf("added at beginning\n");
	}
	else {


		//else loop through the list and find the last node inserted
		   // insert the new node with the correct values for nextnode and previousnode
		   //  INSERT YOUR CODE HERE ************************
		node *current = head;
		while (current->nextnode != NULL)
		{
			current = current->nextnode;
		}
		newnode->previousnode = current;
		current->nextnode = newnode;
		   //   END OF YOUR CODE HERE************************
	}
}

