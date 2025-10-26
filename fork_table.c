#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main ()
{


	int s;
	int pid = fork();
	if(pid == 0)
	{
		//child process
		printf("child table\n");

	for (int i =1 ; i<= 10; i++)
	{

		printf(" %d\n", i*10);
		sleep(1);

	}
	_exit(0);
	}
	else
	{

		//parent process
		waitpid(pid, &s, 0);
		printf("parent :exit status : %d\n",WEXITSTATUS(s));

	}
	printf("parent : program finished\n");
	return 0;
}

