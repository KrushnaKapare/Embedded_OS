#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

//step1 : implement signal handler
void sigint_handler(int sig)
{

   printf("signal caught : %d\n", sig);


}

int main(void)
{
	int i;
	struct sigaction sa;

	//step2 :register signal handler
	memset(&sa, 0, sizeof(struct sigaction));

	// void (*sa_handler)(int); syntax of below code
	sa.sa_handler = sigint_handler;

  // int sigaction(int signum, const struct sigaction *act,struct sigaction *oldact);
  // syntax of below code
	sigaction(SIGINT, &sa,NULL);

	while(1)
	{

		printf("running : %d\n",i);
		i++;
		sleep(2);
	}
	return 0;
}
