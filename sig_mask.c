#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void sig_handler(int sig)
{

	printf("%d signal is received to process %d\n",sig, getpid());

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

	sigemptyset(&set);
   //00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000

	sigaddset(&set, SIGTERM); //SIGTERM = 15 
   //00000000 00000010 00000000 00000000 00000000 00000000 00000000 00000000

	sigaddset(&set, SIGALRM); //SIGALRM = 14
   //00000000 00000110 00000000 00000000 00000000 00000000 00000000 00000000

	//apply above mask to process
	int ret = sigprocmask (SIG_SETMASK, &set, NULL);
	if(ret == -1)
	{
		perror("sigprocmask() is failed");
		_exit(ret);

	}
	while(1)
	{

		printf("running (%d) = %d\n", getpid(), i);
		i++;
		sleep(2);
	}

}
