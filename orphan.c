//A child process whose parent is exited before child completes.
//The init process PID(1) Adopts orphan

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){



	pid_t pid =fork();

	if(pid>0){
	
	printf("parent process PID : %d \n",getpid());
        
        printf("parent exiting \n");	
	exit(0);
	}

	else if(pid==0){
		sleep(5);
		printf("child process PID : %d \n",getpid());
		printf("Parent process PID : %d \n",getppid());
		printf("child exiting \n");
	
	}

	else{
		printf("fork failed");
	
	}
	return 0;
}



