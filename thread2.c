#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int count = 0;
pthread_mutex_t m;
pthread_cond_t c;

int flag = 0;
void *krushna(void *p)
{
	char *str = "KRUSHNA\n";
	pthread_mutex_lock(&m);
	for(int i=0; str[i] != '\0' ; i++)
	{
		putchar(str[i]);
		fflush(stdout);
		sleep(1);
	}
	flag = 1;   // KRUSHNA is Printed
	pthread_cond_signal(&c);
	pthread_mutex_unlock(&m);
	return NULL;
}

 void *kapare(void *p)
   {
       char *str = "KAPARE\n";
      pthread_mutex_lock(&m);
      
	  while(!flag)
		  pthread_cond_wait(&c, &m);
	  for(int i=0; str[i] != '\0' ; i++)
      {
          putchar(str[i]);
          fflush(stdout);
          sleep(1);
      }
      
      pthread_mutex_unlock(&m);
     return NULL;
  }

int main()
{
	pthread_t first, last;
	int ret ;
	pthread_mutex_init(&m, NULL);
	pthread_cond_init(&c, NULL);

	ret = pthread_create(&first, NULL, krushna, NULL);
	ret = pthread_create(&last, NULL, kapare, NULL);

	pthread_join(first, NULL);
	pthread_join(last, NULL);

	pthread_cond_destroy(&c);
	pthread_mutex_destroy(&m);
	return 0;
}
