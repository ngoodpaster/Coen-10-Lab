#include <stdio.h>

int main(void)
{
	int i;
	int x[12] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12};
	for (i = 6 ; i >= 0 ; i--)
	{	
		x[i+5] = x[i];
	}
	

	for (i = 0 ; i < 5 ; i++)
		x[i] = 0;
	for (i = 0 ; i < 12 ; i++)
		printf ("%d\n"  , x[i]);
	
	return 0;
}
