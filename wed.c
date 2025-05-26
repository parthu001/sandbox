#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int main(){
//	pid_t pid=fork();
//
printf("execl failed");

execl("/bin/ls","ls",NULL);

printf("this printf will runs only after fail");
return 0;



}

