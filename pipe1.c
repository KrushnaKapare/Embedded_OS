#include<stdio.h>
#include<unistd.h>
#include<string.h>

//simple read and write operation using pipe
int main(void)
{

	int arr[2];

	//create a pipe - arr[0] = read end arr[1] = write end

	int ret = pipe(arr);
	if (ret == -1)
	{

		perror("pipe() is failed");
		_exit(-1);

	}

	//write into pipe from write end
	char msg1[64] ="GOOD Morning!!!";
	write(arr[1], msg1 , strlen(msg1));
	printf("msg is written into pipe\n");

	//read from pipe form read end
	char msg2[64];
	read(arr[0],msg2,sizeof(msg2));
	printf("msg read from pipe : %s\n", msg2);

	//close both the ends of pipe
	close(arr[0]);
	close(arr[1]);

	return 0;
}
