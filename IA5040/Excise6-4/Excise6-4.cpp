// Excise6-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	char* value;
	int sizeofvalue;
	int count;
	struct node *nextnode;
	struct node *previousnode;
};
struct list {
	struct node  *head;
	struct node  *tail;
	int           size;
};
char * inputWords[] = { "I", "had", "I","so", "word","low","high","hello","much", "fun", "bye","with","I","hello","I","small","small","big","big","hello" };
int numWords = 20;

void printfromhead(struct list theList); // print elements from head to tail
void printfromtail(struct list theList); // print elements from tail to head
void cleanup(struct list theList);
struct node* searchnode(char* word, struct list *list);
void incrementcount(struct node *node);
struct node* sortnode(struct node *node, struct list *list);
struct node* createnode(char* word, struct list *list);

int main()
{

	char *localword;
	char *ptr;
	struct list theList;
	theList.head = NULL;
	theList.tail = NULL;
	theList.size = 0;
	int i = 0;
	while (i < numWords)
	{

		localword = inputWords[i];
		ptr = localword;

		struct node* node = searchnode(ptr, &theList);
		if (node != NULL)
		{
			incrementcount(node);
			sortnode(node, &theList);
		}
		else {
			createnode(ptr, &theList);
		}
		i++;
	}
	printfromhead(theList); // if we wanted to print in increasing order
	printfromtail(theList);  // We want print in decreasing order
	getchar();
	cleanup(theList);
	return 0;
}
void printfromhead(struct list theList)
{
	printf("Print List from head here!\n");
	struct node* current = theList.head;
	while (1)
	{
		printf("%s\n", current->value);
		current = current->nextnode;
		if (current == NULL)
			break;
	}
	printf("NumNodes:%i  End of print from head!\n", theList.size);

}
void printfromtail(struct list theList)
{
	// get the tail elements in the double linked list
	struct node *temp = theList.tail;
	while (true)
	{
		printf("%s\n", temp->value);

		// keep looping previous value of the double linked list
		temp = temp->previousnode;
		if (temp == NULL)
		{
			break;
		}
	}

	printf("NumNodes:%i  End of print from tail!\n", theList.size);
}
void cleanup(struct list theList)
{

	printf("Cleanup dynamically allocated memory\n");
	struct node* current = theList.head->nextnode;
	while (1)
	{
		printf("%s memory freed\n", current->previousnode->value);
		free(current->previousnode);
		current = current->nextnode;
		if (current == NULL)
			break;
	}
	printf("All memory has been freed!\n");
}
struct node* searchnode(char* word, struct list *list)
{
	//get first element in the double linked list
	struct node *temp = list->head;
	if (temp == NULL) return temp;

	// loop list to find the world match
	while ( temp->nextnode != NULL)
	{

		if (temp->value == word)
		{
			return temp;
		}
		temp = temp->nextnode;
	}
	// if the head is the last element in the double linked list
	// then find match.
	if (temp->nextnode == NULL)
	{
		if (temp->value == word)
		{
			return temp;
		}
		return NULL;
	}
	return NULL;
}
void incrementcount(struct node *node)
{
	// if the node has already exist
	// increase the node count
	node->count++;
}
struct node* sortnode(struct node *mynode, struct list *list)
{
	struct node *current = mynode->nextnode;
	struct node *lastcurrent = NULL;
	if (current == NULL)
	{
		return NULL;
	}
	while (current != NULL)
	{
		if (mynode->count >= current->count)
		{
			lastcurrent = current;
			current = current->nextnode;
		}
		else
		{
			if (mynode->previousnode != NULL)
			{
				mynode->previousnode->nextnode = mynode->nextnode;
				mynode->nextnode->previousnode = mynode->previousnode;
			}
			else {
				mynode->nextnode->previousnode = NULL;
				list->head = mynode->nextnode;
			}
			mynode->nextnode = current;
			mynode->previousnode = current->previousnode;
			current->previousnode->nextnode = mynode;
			current->previousnode = mynode;

			return mynode;
		}
	}
	if (mynode->previousnode != NULL)
	{
		mynode->previousnode->nextnode = mynode->nextnode;
		mynode->nextnode->previousnode = mynode->previousnode;
	}
	else {
		mynode->nextnode->previousnode = NULL;
		list->head = mynode->nextnode;
	}
	lastcurrent->nextnode = mynode;
	mynode->nextnode = NULL;
	mynode->previousnode = lastcurrent;
	list->tail = mynode;
	if (list->size == 2)
	{
		list->head = lastcurrent;
	}
	return mynode;
}
struct node* createnode(char* word, struct list *list)
{
	// assign memory address to the structure
	node *newnode = (node*)malloc(sizeof(node));
	// if no memory quit the application
	if (newnode == NULL) {
		fprintf(stderr, "Unable to allocate memory for new node\n");
		exit(-1);
	}

	// initialize the structure
	newnode->value = word;
	newnode->nextnode = NULL;
	newnode->previousnode = NULL;
	newnode->count = 0;
	newnode->sizeofvalue = sizeof(newnode->value);

	// add element to the head of the double linked list

	if (list->tail == NULL)
	{
		// if double linked list has 0 element
		// create a node and assign to the list tail element
		newnode->count++;
		list->tail = newnode;
		list->size++;
	}
	else
	{
		// if the list has its tail element
		// add new node to the head of the doubled linked list
		node *temp = list->tail;

		while (temp->previousnode != NULL)
		{
			temp = temp->previousnode;
			list->size++;
		}
		newnode->count++;
		newnode->nextnode = temp;
		temp->previousnode = newnode;
		list->head = newnode;
	}
}