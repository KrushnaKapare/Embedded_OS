#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(void)
{
	int pid = fork();
	if (pid == 0)
	{
		int ifd, ofd, efd;

		//input redirection 
		ifd = open("in.txt", O_RDONLY);
		close(0);
		dup(ifd);
		close(ifd);

		//output redirection 
		ofd = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		close(1);
		dup(ofd);
		close(ofd);
          
		//error redirection 
		efd = open("err.txt",O_WRONLY | O_TRUNC | O_CREAT, 0644);
		close(2);
		dup(efd);
		close(efd);

		//child
		int ret = execl("/usr/bin/bc", "bc", NULL);
		if(ret == -1)
		{

			perror("execl() is failed");
			_exit(-1);
		}
	}

	else
	{

		//parent 
		int s;
		waitpid(-1 , &s , 0);
		printf("Exit status of child : %d\n", WEXITSTATUS(s));
	}
	return 0;
}
