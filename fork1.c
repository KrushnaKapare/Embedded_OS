#include<stdio.h>
#include<unistd.h>


int main(void)
{


	printf("program started---\n");
   	int ret = fork();
	printf("fork return = %d\n",ret);
	printf("*****************\n");
	printf("program finished...\n");


	return 0;
}





