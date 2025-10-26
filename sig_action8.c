#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

//step1 : implement signal handler
//syntax:
// void (*sa_sigaction)(int, siginfo_t *, void *);

void sigint_handler(int sig, siginfo_t *info,void *ucontext)
{

   printf("signal caught : %d\n", info->si_signo);
   printf("sender process : %d\n", info->si_pid);

}

int main(void)
{
	int i;
	struct sigaction sa;

	//step2 :register signal handler
	memset(&sa, 0, sizeof(struct sigaction));

	// void (*sa_handler)(int); syntax of below code
	sa.sa_sigaction = sigint_handler;

	// int sa_flags; 
	//assigning member a value 
	sa.sa_flags = SA_SIGINFO;
  
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
