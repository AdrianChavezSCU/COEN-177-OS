#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{
	int status = 0;	
	char cmd[10]; //array of characters that make up the: command
	char* inputs[2]; //array of strings for the commands
	while(1)
	{
		
		printf("Enter Command: \n");
		scanf("%s", &cmd); //reading strings  in from the command line
		if(strcmp("exit",cmd) == 0 ) //comparing the string to 'exit'
		{
			printf("GG Mate \n");
			exit(1); //terminate the child process 1st; and then the parent
		}
		if(fork() !=0)
		{
			waitpid(-1, &status, 0);
		}
		else
		{
			/*child code*/
			inputs[0] = cmd; //checks the command saved at 0
			inputs[1] = NULL; //identifies empty data
			execvp(inputs[0],inputs); //executes first command  array of strings
		} 
		
	}		


}
