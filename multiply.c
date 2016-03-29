#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int x;
	int number1;
	int number2;
	int number3;
	int counter = 0;
	int i;
	srand ((int) time (NULL));
	for (i=0 ; i<10 ; i++)
	{	
		number1 = rand()%13;
		number2 = rand()%13;
		number3 = number1 * number2;
		printf ("%d * %d =\n" , number1 , number2);
		printf ("Answer: ");
		scanf ("%d" , &x);
		if (x == number3)
		{
			printf ("Correct!\n");
			counter++;
			printf ("\n");
		}
		else
		{
			printf ("Incorrect! The answer is %d\n" , number3);
			printf ("\n");
		}
	}
	printf ("You answered %d problems correct\n" , counter);
	printf ("\n");
	
	return 0;
}
