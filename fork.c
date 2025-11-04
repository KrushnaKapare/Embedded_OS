#include<stdio.h>
#include<unistd.h>




// basic process creation program 
//using fork()
int main(void)
{


	printf("program started---\n");
	fork();
	printf("program finished...\n");

	return 0;
}





