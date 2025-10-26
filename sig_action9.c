#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

//implement SIGCHLD Signal to avoid zombie process

//step1 : implement signal handler
//syntax:
// void (*sa_sigaction)(int, siginfo_t *, void *);

void sigchld_handler(int sig, siginfo_t *info,void *ucontext)
{

   printf("Received SIGCHLD :( %d ) signal to process (%d)\n", sig, getpid());
   printf("sender process ID : %d\n", info->si_pid);
   int s;
   wait(&s);
   printf("Exit status of child : %d\n", WEXITSTATUS(s));

}

int main(void)
{
	
	struct sigaction sa;


	// void (*sa_handler)(int); syntax of below code
	sa.sa_sigaction = sigchld_handler;

	// int sa_flags; 
	//assigning member a value 
	sa.sa_flags = SA_SIGINFO;
  
	// int sigaction(int signum, const struct sigaction *act,struct sigaction *oldact);
    // syntax of below code
	sigaction(SIGCHLD, &sa,NULL);

	int pid = fork();
	if(pid == 0)
	{
		//child 
		for(int i=0 ; i<5; i++)
		{
			printf("child(%d) : i = %d\n",getpid(), i);
			sleep(1);
		}
		_exit(0);

	}
	else
	{
		//parent 
		for(int i = 0; i<10; i++)
		{
			printf("parent (%d) : i = %d\n",getpid(),i);
			sleep(1);

		}
	}
	return 0;
}
