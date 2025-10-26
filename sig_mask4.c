#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)

{
	printf("signal caught : %d [process ID = %d]\n",sig,getpid());
	for(int i =0 ; i<5 ; i++)
	{

		printf("inside SIGINT handler : %d\n", i);
		sleep(2);
	}
}

int main(void)
{

	int i;
	signal(SIGINT, sigint_handler);

	while(1);
	return 0;
}
