#include<stdio.h>
#include<stdlib.h>

int main()
{
	long unsigned int size = 1 * 1024 * 1024 * 1024;
	
	for(int i=1; i<=100; i++)
	{
		char *ptr = (char*) malloc (size);
		printf("malloc(%d) returned :%p \n", i,ptr);
		getchar();
	}
	return 0;
}

