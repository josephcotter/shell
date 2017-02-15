//JOEY COTTER LAB 1 PART 1 SHELL 
//My shell is almost exactly like the one taught in class. It first prompts the user for a command. If the command is "exit", the shell program exits. Otherwise, the shell forks and waits while the child attempts to execv the command. If this fails, the child exits and the shell prompts the user again. Otherwise the shell waits for the child to die, then prompts the user again. 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *cmdstr;
size_t bufsize = 64;
int pid;

void main()
{
	cmdstr = (char *)malloc(bufsize * sizeof(char));
	if( cmdstr == NULL)
	{
		printf("Buffer allocation failed");
		exit(0);
	}
	while (1)
	{
		printf("[JOEY'S SHELL]$: ");
			
		getline(&cmdstr, &bufsize, stdin); // reading command 
	
		cmdstr[strlen(cmdstr)-1] = 0; // removing newline character at the end of command, didn't work otherwise 
	
		if (strcmp(cmdstr, "exit") == 0) // if command is exit, exit
			exit(0);

		pid = fork(); //if command is somthing else, fork
	
		if (pid) // if parent, wait for child process to complete
			wait(0);
	  
		else
		{
			execve(cmdstr, NULL, 0); // attempting to run command program
	    		printf("launch failed\n"); // if this code runs, it means execve failed. exit child process
			exit(0); 
		}

	}
}
