// quiz 1-8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int c,i;
	int counter = 0;
	for (i = 0; (c = getchar()) != EOF; i++)
	{
		if (c == 'a'|| c == 'e' || c == 'i'	|| c == 'o'|| c == 'u')
		{
			counter++;
		}

	}

	printf("The number of lower case vowel (a,e,i,o,u) is: \t%d\n",counter);

	getchar();
    return 0;
}

