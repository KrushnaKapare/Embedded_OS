#include<stdio.h>
#include<unistd.h>


int main(void)
{


	printf("pid =%d, ppid = %d\n",getpid(),getppid());
	printf("program started---\n");
   	int ret = fork();

	printf("pid =%d, ppid = %d\n",getpid(),getppid());
	printf("fork return = %d\n",ret);
	printf("program finished...\n");


	return 0;
}





