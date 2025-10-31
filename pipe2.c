#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

// read and write operation using pipe with two processes
int main(void)
{

	int arr[2];
	int ret = pipe(arr);
	if (ret == -1)
	{

		perror("pipe() is failed");
		_exit(-1);

	}

	int pid = fork();
	if (pid == 0)
	{
	//child process --> writer 
	close(arr[0]);       // close the read end of pipe
	char msg1[64];
	printf("ENTER MSG : ");
	scanf("%[^\n]s", msg1);
	write(arr[1], msg1 , strlen(msg1));
	printf("child : msg is written into pipe\n");
	close(arr[1]);
    }

	else
	{
     // parent process --> reader
	close(arr[1]);    // close the write end of pipe
	printf("parent : waiting for msg ...\n");
	char msg2[64];
	read(arr[0],msg2,sizeof(msg2));
	printf("parent : received msg : %s\n", msg2);
	close(arr[0]);
	
	int s;
	wait(&s);
    }
	return 0;
}
