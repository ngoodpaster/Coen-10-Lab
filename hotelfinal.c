#include <stdio.h>
#include <string.h>

char x[10][20];
int counterROOM = 10;
char *p;


void reserve (char *w)
{
	int i;
	int j;
	int k;
	int l;
	int flag5;
	int y;
	int a;
	char b;
	int consec = 0;
	int room[20];
	int flag1 = 0;
	int flagA = 0;
	p = x[0];
	for (i = 0 ; i < 10 ; i++ , p+=20)	
	{
		if (*p == '\0')
			flag1 = 1;
	}
	if (flag1 == 0)
	{
		printf ("Sorry, Hotel is Full.\n");
		return;
	}
	else
	{
		printf ("There are %d rooms available.\n" , counterROOM);
		printf ("How many rooms would you like to reserve?\n");
		scanf ("%d" , &a);
		if (counterROOM < a)
		{
			printf ("Sorry, we can only reserve %d rooms for you.\n" , counterROOM);
			a = counterROOM;
		}
		for ( ; ; )
		{
			p = x[0];
			for (j = 0 ; j < 10 ; j++ , p+=20)
			{
				flag5 = 0;	
				if (strcmp (p , w) == 0)
				{	
					printf ("Sorry, this name is already taken.\n");
					printf ("Please choose a new name.\n");
					flag5 = 1;
					j = 9;
				}
			}
			if (flag5 == 0)
				break;
		}
		p = x[0];
		for (i = 0 ; i < 10 ; i++ , p+=20)	//!EXTRA CREDIT From Lab 9!
		{
			if (*p == '\0')
			{
				consec++;
				if (consec == a)
				{
					p -= (a-1)*20;   //sends pointer to first of the consecutive empty strings
					i -= (a-1);     //sets i for next for loop to start first of consecutive empty strings
					flagA = 1;
					break;
				}
			}
			else
				consec = 0;
		}
		if (flagA == 0)   //checks if there were enough consecutive empty strings 
		{
			p = x[0];  //sets pointer and i back to first string
			i = 0;
		}
		for ( j = 0 ; j < a ; i++ , p+=20)        //traverses global until "a" amount of rooms have been reserved
		{
			if (*p == '\0')
			{
				strcpy (p , w);
				room[j] = i+1;      //initiates new array "room" with room numbers reserved
				j++;                 //only increments j when string is empty
			}
		}
		printf ("The following rooms have been reserved under the name, %s:\n" , w);
		printf ("Rooms:  ");
		for (l = 0 ; l < a ; l++)              //prints the room numbers the customer reserved
			printf ("%d  " , room[l]);  
		printf ("\n");
		printf ("Thank You for choosing to stay at The Goodpaster Hotel!");
		printf ("\n");
		counterROOM -= a;
		i = 9;
	}
	return;
}


void cancel (char *w)
{
	int i;
	int flag4;
	int flag2;
	int count = 0;
	char pos;
	int flag9 = 0;
	flag4 = 0;	
	p = x[0];
	for (i = 0 ; i < 10 ; i++ , p+=20)	
	{
		if (*p != '\0')
			flag4 = 1;
	}
	if (flag4 == 0)
		printf ("Hotel is empty.\n");
	else
	{ 
		flag2 = 0;
		p = x[0];
		for (i = 0 ; i < 10 ; i++ , p+=20)
		{
			if (strcmp (p , w) == 0)
			{	
				if (flag9 == 0)
				{
					pos = i;
					flag9 = 1;
				}
				*p = '\0';
				count++;
				counterROOM++;
				flag2 = 1;
			}
		}
		if (flag2 == 0)
			printf ("There were no reservations found for the name: %s.\n" , w);
		else 
		{
			printf ("Have a nice day, and stay with us next time, %s!\n" , w);
			printf ("\n");
		}
	}
	p = x[pos];
	for (i = pos ; i < 10-count ; i++ , p+=20)
	{	
		strcpy (p , p + count*20);
		*(p + count*20) = '\0';
	}
	return;
}


void list (void)
{
	int i;
	int flag3;
	char name[20];
	flag3 = 0;
	p = x[0];
	for (i = 0 ; i < 10 ; i++ , p+=20)	
	{
		if (*p != '\0')
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
		p = x[0];
		for (i = 0 ; i < 10 ; i++ , p+=20)
			printf ("Room #%d: %s\n" , i+1 , p);		
	}
}


int main (void)
{
	int i;
	int y;
	char name[20];
	p = x[0];
	for (i = 0 ; i < 10 ; i++ , p+=20)	
		*p = '\0';		
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
				printf ("Please enter your name.\n");
				scanf ("%s" , name);
				reserve(name);	
				break;
			case (1):
				printf ("What is your Name?\n");
				scanf ("%s" , name);
				cancel(name);
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


