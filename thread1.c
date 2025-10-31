#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t m;  
void *incr(void *param)
{
	int i,ret;
	for(i=1; i<=10000; i++)
	{
	
		ret = pthread_mutex_lock(&m);
		if (ret != 0)
		{
			perror("pthread_mutex_lock()");
			exit(0);
		}
		count = count+1;
		ret = pthread_mutex_unlock(&m);
		if(ret != 0)
		{
			perror("pthread_mutex_unlock()");
			exit(0);
		}
	}
	return NULL;
}

void *decr(void *param)
{
	int i,ret;
	for(i=1; i<=10000; i++)
	{
		 ret = pthread_mutex_lock(&m);
          if (ret != 0)
          {
              perror("pthread_mutex_lock()");
              exit(0);
          }

		count = count -1;
	 ret = pthread_mutex_unlock(&m);
          if (ret != 0)
          {   
              perror("pthread_mutex_unlock()");
              exit(0);
          }


	}
	return NULL;
}

int main()
{
	pthread_t it, dt;
	pthread_mutexattr_t ma;  

	// init mutex attributes
	pthread_mutexattr_init(&ma);  // default mutex attr init

#ifdef DEBUG
	pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_ERRORCHECK);
	printf("using error checkin mutex\n");
#else
	pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_NORMAL);
	printf("using normal checking mutex\n");
#endif

	//create mutex with given attrs
	pthread_mutex_init(&m, &ma);
	pthread_create(&it, NULL, incr, NULL);
	pthread_create(&dt, NULL, decr, NULL);
	pthread_join(it, NULL);
	pthread_join(dt, NULL);

	printf("final count: %d \n",count);
	pthread_mutex_destroy(&m);
	return 0;
}

