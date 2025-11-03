#include<stdio.h>
#include<stdlib.h>

// allocating virtual memory 

int main ()
{
	unsigned int size = 1 * 1024 * 1024 * 1024;
	char *ptr = (char *) malloc(size);

	printf("malloc() returned: %p \n", ptr );
	getchar ();
	free(ptr);
	ptr =  NULL;
	return 0;
}

