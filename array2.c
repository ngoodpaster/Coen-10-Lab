#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
	srand ((int) time (NULL));
	int i , temp;
/*	int temp */
	int x[7];
	for (i = 0 ; i < 7 ; i++)
		x[i] = rand()%21;
	printf ("Initial Array:\n");
	for (i = 0 ; i < 7 ; i++)
		printf ("%d\n" , x[i]);
		printf ("\n");
	for (i = 0 ; i < 7/2 ; i++)
	{
		temp = x[i];
		x[i] = x[6 - i];
		x[6-i] = temp;
	}
	
	printf ("Reversed Array:\n");
	for (i = 0 ; i < 7 ; i++)
		printf ("%d\n" , x[i]);

	return 0;
}
