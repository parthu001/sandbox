//A zombie process is a child process that has completed the execution but still has entry in the process table because parent hasnt read the exit status

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(){

	pid_t pid=fork();

	if(pid >0){
		printf("parent process pid : %d \n",getpid());
		sleep(10);

		printf("parent exiting \n");
	}

	else if(pid==0){
		printf("child process pid : %d \n ",getpid());

		printf("child exiting \n");
		exit(0);
	}

	else{
		printf("fork failed");
	}
	return 0;
}

