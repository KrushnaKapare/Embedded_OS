#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// zombiee process code
// if child process terminate before parent process 
// then that process is called zombiee process 

int main(void)
{
    


	int  i;
	printf("***program started***\n");
	int ret = fork();

	if(ret == -1)
	{

		printf("child process is not created :(\n");
		exit(ret);
	}

	else if(ret == 0)
	{

		//child process
		
		for(i=10;i>0;i--)
		{

			printf("child : i = %d\n",i);
			sleep(1);

		}
		
	}
	else
	{

		//parent process
		for(i=1;i<=15;i++)
		{
			printf("parent: i = %d\n",i);
			sleep(1);
		}
	}
	printf("program finished :)\n\n");

	return 0;

}
