#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	//open pipe file in read mode
	int fd = open("./myfifo", O_RDONLY);

/*	if ( fd == -1)
	{
		printf("File is not opened...");
		_exit(-1);
	}
*/
	//write data into pipe
	char str[20];
    read(fd, str,sizeof(str));
	printf("Received data : %s\n",str);

	//close the file descriptor
	close(fd);

	return 0;
}
