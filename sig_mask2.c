#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void sig_handler(int sig)
{

	printf("Signal caught : %d [ process ID = %d ]\n",sig, getpid());

}

int main(void)
{
	int i =0 ;
	struct sigaction sa;
	memset(&sa, 0 , sizeof(struct sigaction));
	sa.sa_handler = sig_handler;

	//register signal handler for SIGINT signal 
	sigaction(SIGINT, &sa, NULL);

	//register signal handler for SIGTERM signal
	sigaction(SIGTERM, &sa, NULL);

	//mask the signals -SIGTERM and SIGALRM
	sigset_t set;

	sigfillset(&set);
       
	sigdelset(&set, SIGTERM); //SIGTERM = 15 

	sigdelset(&set, SIGALRM); //SIGALRM = 14

	sigdelset(&set,SIGSEGV);

	printf("waiting for signal SIGTERM/SIGALRM/SIGSEGV....\n");
	sigsuspend(&set);

	printf("bye\n");
	return 0;

}
