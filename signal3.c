#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//step 1 : implement signal handler
void signal_handler(int sig)
{

	switch(sig)
	{

		case SIGINT: 
			printf("SIGINT Signal caught : %d\n", sig);
			break;
		case SIGTERM:
			printf("SIGTERM Signal caught : %d\n", sig);
			break;
		case SIGALRM:
			printf("SIGALRM Signal caught : %d\n", sig);
			break;
		default:
			printf(" Signal caught : %d\n", sig);
	}
}

void sigsegv_handler(int sig)
{

	printf("SIGSEGV : Signal Caught : %d \n", sig);
	_exit(1);
}

int main()
{
	int i;

	//step 2 : register signal handler
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGSEGV, sigsegv_handler);
    signal(SIGALRM, signal_handler);

	while(1)
	{

		printf("running : %d\n", i);
		i++;
		sleep(2);

	}

	return 0;

}
