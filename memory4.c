#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int size = 1 *1024*1024*1024;
	char *ptr = (char *) malloc(size);
	printf("malloc() returned : %p\n", ptr);
	int count=0;
	for(int i=0; i<size; i+=4096)
	{
		ptr[i] ='A';
		count++;
		printf("Count = %d \n", count);
	}
	printf("written on memory allocated by malloc(). \n");
	getchar();
	free(ptr);
	ptr = NULL;
	return 0;

}
