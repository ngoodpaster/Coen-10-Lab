#include <stdio.h>

int main (void)
{
	int i;
	int y;
	int z;
	int flag1;
	int flag2;
	int flag3;
	int counterID = 1;
	int counterROOM = 10;
	int x[10];
	for (i = 0 ; i < 10 ; i++)	
		x[i] = 0;	
	
	printf ("\n");
	printf ("Hello, and Welcome to The Goodpaster Hotel in sunny Santa Clara, Califonia!");
	printf ("\n");
	for ( ; ; )
	{
		printf ("\n");
		printf ("How can we help you today?\n");
		printf ("\n");
		printf ("To reserve a room press 0\n");
		printf ("To cancel a reservation press 1\n");
		printf ("To see room availability press 2\n");
		printf ("To quit press another number\n");
		printf ("\n");
		scanf ("%d" , &y);
		if ( y == 0)
		{	
			flag1 = 0;
			for (i = 0 ; i < 10 ; i++)
			{
				if ( x[i] == 0 )
				{
					printf ("Your Reservation ID Number is %d\n" , counterID);
					printf ("Your Room Number is %d\n" , i+1);
					printf ("Thank You for choosing to stay at The Goodpaster Hotel!");
					printf ("\n");
					x[i] = counterID;
					counterID++;
					counterROOM--;
					flag1 = 1;
					i = 9;

				}
			}
			if (flag1 == 0)
				printf ("Sorry, Hotel is Full\n");
		}
		else if (y == 1)
		{		
			printf ("What is your Reservation ID Number?\n");
			scanf ("%d" , &z);
			flag2 = 0;
			for (i = 0 ; i < 10 ; i++)
			{
				if ( x[i] == z)
				{
					printf ("Have a nice day, and stay with us next time!");
					x[i] = 0;
					counterROOM++;
					flag2 = 1;
					i = 9;
				}
			}
			if (flag2 == 0)
				printf ("There were no reservations found for ID Number: %d\n" , z);
		}
		else if (y == 2)	
		{
			for (i = 0 ; i < 10 ; i++)
			{
				if (x[i] != 0)
					flag3 = 1;
			}
			if (flag3 == 0)
			{
				printf ("\n");
				printf ("The Hotel is empty.\n");
			}
			else
			{	
				printf ("\n");
				printf ("There are %d rooms available\n" , counterROOM);
				printf ("(0's signify rooms that are available)");
				printf ("\n");
				for (i = 0 ; i < 10 ; i++)
					printf ("Room #%d: %d\n" , i+1 , x[i]);		
			}
		}
		else 		
			return 0;
	}
	
	/* for (i = 0 ; i < 10 ; i++)	
		printf ("%d\n" , x[i]);
	
	return 0; */
}
