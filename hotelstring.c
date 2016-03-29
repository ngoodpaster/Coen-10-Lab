#include <stdio.h>
#include <string.h>

int main (void)
{
	int i;
	int y;
	int q;
	char name[20];
	int flag1;
	int flag2;
	int flag3;
	int flag4;
	int counterROOM = 10;
	char x[10][20];
	for (i = 0 ; i < 10 ; i++)	
		x[i][0] = '\0';	
	
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
				if ( x[i][0] == '\0' )
				{
					printf ("Please enter your name\n");
					scanf ("%s" , x[i]);
					printf ("Your Room Number is %d\n" , i+1);
					printf ("Thank You for choosing to stay at The Goodpaster Hotel!");
					printf ("\n");
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
			flag4 = 0;	
			for (i = 0 ; i < 10 ; i++)
			{
				if (x[i][0] != '\0')
					flag4 = 1;
			}
			if (flag4 == 0)
				printf ("Hotel is empty.\n");
			else
			{ 
				printf ("What is your Name\n");
				scanf ("%s" , name);
				flag2 = 0;
				for (i = 0 ; i < 10 ; i++)
				{
					if (strcmp (x[i] , name) == 0)
						flag2++;
				}
				if (flag2 >= 2)
				{
					printf ("What is your room number?\n");
					scanf ("%d" , &q);
					for (i = 0 ; i < 10 ; i++)
					{
						if (i == q-1)
						{
							printf ("Have a nice day, and stay with us next time!");
							x[i][0] = '\0';
							i = 9;
							counterROOM++;
						}	
					}
				}
				else if (flag2 == 1)
				{
					for (i = 0 ; i < 10 ; i++)
					{
						if (strcmp (x[i] , name) == 0)
						{	
							printf ("Have a nice day, and stay with us next time %s!" , name);
							x[i][0] = '\0';
							counterROOM++;
							i = 9;
						}
					}
				}
				else
					printf ("There were no reservations found for the name: %s\n" , name);
			}
		}
		else if (y == 2)	
		{
			flag3 = 0;
			for (i = 0 ; i < 10 ; i++)
			{
				if (x[i][0] != '\0')
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
				printf ("(The rooms with names assigned to them are taken.)");
				printf ("\n");
				for (i = 0 ; i < 10 ; i++)
					printf ("Room #%d: %s\n" , i+1 , x[i]);		
			}
		}
		else 		
			return 0;
	}  
	
	return 0; 
}
