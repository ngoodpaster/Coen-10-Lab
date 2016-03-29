#include <stdio.h>
#include <string.h>

char x[10][20];
int counterROOM = 10;


void reserve (void)
{
	int i;
	int j;
	int flag5;
	int y;
	char name[20];
	int flag1;
	flag1 = 0;
	for (i = 0 ; i < 10 ; i++)
	{
		if ( x[i][0] == '\0' )
			flag1 = 1;
	}
	if (flag1 == 0)
	{
		printf ("Sorry, Hotel is Full\n");
		return;
	}
	else
	{
		printf ("Please enter your name\n");
		for ( ; ; )
		{
			scanf ("%s" , name);
			for (j = 0 ; j < 10 ; j++)
			{
				flag5 = 0;	
				if (strcmp (x[j] , name) == 0)
				{	
					printf ("Sorry, this name is already taken\n");
					printf ("Please choose a new name\n");
					flag5 = 1;
					j = 9;
				}
			}
			if (flag5 == 0)
				break;
		}
		for (i = 0 ; i < 10 ; i++)
		{
			if ( x[i][0] == '\0' )
			{
				strcpy (x[i] , name);
				printf ("Your Room Number is %d\n" , i+1);
				printf ("Thank You for choosing to stay at The Goodpaster Hotel!");
				printf ("\n");
				counterROOM--;
				i = 9;
			}
		}
	}
	return;
}


void cancel (void)
{
	int i;
	char name2[20];
	int flag4;
	int flag2;
	int q;
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
		scanf ("%s" , name2);
		for (i = 0 ; i < 10 ; i++)
		{
			flag2 = 0;
			if (strcmp (x[i] , name2) == 0)
			{	
				printf ("Have a nice day, and stay with us next time, %s!" , name2);
				x[i][0] = '\0';
				counterROOM++;
				flag2 = 1;
				i = 9;
			}
		}
		if (flag2 == 0)
			printf ("There were no reservations found for the name: %s\n" , name2);
	}
	
	return;
}


void list (void)
{
	int i;
	int flag3;
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


int main (void)
{
	int i;
	int y;
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
		switch (y)
		{
			case (0):
				reserve();	
				break;
			case (1):
				cancel();
				break;
			case (2):
				list();
				break;
			default:
				return 0;
		}
	}  
	
	return 0; 
}


