#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

void *thread_func(void *param)
{
	int i;
	for(i=1; i<=10; i++)
	{
		printf("incr (tid=%d): %d\n", gettid(), i);
		sleep(1);

	}
	return NULL;
}

void sigint_handler(int sig)
{
	printf("signal caught: %d --- by thread (tid=%d)\n", sig, gettid());
}

int main()
{
	pthread_t th;
	printf("main thread (tid=%d)\n",gettid());
	signal(SIGINT, sigint_handler);
	pthread_create(&th, NULL, thread_func, NULL);
	printf("press enter to send signal to thread.. \n");
	getchar();

	//pthread_cancel(th);

	pthread_kill(th, SIGINT);
	sleep(1);
	printf("bye\n");
	return 0;
}
