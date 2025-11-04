#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
	printf("program started---\n");
   	int ret = fork();

	if(ret == -1)
	{

		printf("failed to create child process\n");
		exit(ret);
	}

	else if(ret ==0)
	{
	printf("child process is created\n");
	printf("process id( pid)= %d\tparent pid (ppid)= %d\n",getpid(),getppid());
	printf("child : fork returned =%d \n",ret);
	printf("\n");

}
	else
	{

		printf("parent process is created\n");
	    printf("process id( pid)= %d\tparent pid (ppid)= %d\n",getpid(),getppid());
		printf("parent : fork returned =%d \n",ret);
	printf("\n");
	}
	printf("program finished...\n");
	return 0;
}





