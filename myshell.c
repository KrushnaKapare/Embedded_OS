#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


int main(void)

{

	char cmd[256];
	char *args[10], *ptr;
	int i =0;

	while (1)
	{

		//take comamnd form user 
		printf("cmd>");
		gets(cmd);
		//interpret commands
		i =0;
		ptr = strtok(cmd, " ");
		do
		{

			args[i++] =ptr; 
			ptr = strtok(NULL, " ");

		}while(ptr != NULL);
		args[i] =NULL;

		//execute command = internal 
		if (strcmp(args[0], "exit") == 0)
			_exit(0);
		else if(strcmp(args[0], "cd") ==0 )
			chdir(args[1]);
		// execute command -external
		else
		{
			int pid = fork();
			if(pid == 0)
			{

			//child
			int ret = execvp(args[0],args);
			//err check

			}
			else
			{
			   //parent 
			   int s;
			   wait(&s);

			}
		
		}
	}

	return 0;
}
