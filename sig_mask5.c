#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

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

	struct sigaction sa;
	memset (&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	sigfillset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);

	//signal(SIGINT, sigint_handler);

	i=0;
	while(1)
	{
		printf("running : %d\n", i++);
		sleep(2);
	}
	return 0;
}
