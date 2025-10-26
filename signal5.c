#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{

	printf("signal caught in process (%d) : %d \n",getpid(),sig);

}

int main (void)
{

	int i;

	signal(SIGINT, sigint_handler);

	while(1)
	{

		printf("running (%d) : %d \n",getpid(), i);
		i++;
		sleep(2);
	}
	return 0;
}
