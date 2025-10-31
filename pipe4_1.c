#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	//open file in write mode
	int fd = open("./myfifo", O_WRONLY);
/*
	if ( fd == -1)
	{
		printf("File is not opened...");
		_exit(-1);
	}
*/
	//write data into pipe
	char str[20];
	printf("enter string: ");
	scanf("%[^\n]s", str);
	write(fd,str, strlen(str));

	//close the file descriptor
	close(fd);

	return 0;
}
