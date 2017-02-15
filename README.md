# shell
A simple shell, written in C, to run on Unix machines. 
It first prompts the user for a command. If the command is "exit", the shell program exits. Otherwise, the shell forks and waits while the child shell attempts to execv the command. If this fails, the child process exits and the original shell prompts the user again. Otherwise the shell waits for the child process to die, then prompts the user again. 
