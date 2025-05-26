#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process. PID = %d\n", getpid());
    } else if (pid > 0) {
        printf("Parent process. PID = %d\n", getpid());
    } else {
        perror("fork failed");
    }

    return 0;
}

