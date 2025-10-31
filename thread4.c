#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread1_fun(void *param)
{
	int i;
	for(int i=0; i<10; i++)
	{
		printf("thread1 = %d\n", i);
				sleep(1);
	}
	return NULL;
}

void *thread2_fun(void *param)
{
	int i, pid;
	for(i=1; i<=10; i++)
	{
		printf("thread2 :%d\n",i);
		sleep(1);
		if(i == 5)
		{
			pid == fork();
			if (pid == 0)
			  printf("child process created..\n");
	}
	}
	return  NULL;

}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread1_fun, NULL);
	pthread_create(&t2, NULL, thread2_fun, NULL);
	for(int i =0; i<10; i++)
	{
		printf("main :%d\n",i);
		sleep(1);
	}
	return 0;
}


