#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void create_daemon() {
    pid_t pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);  // Parent exits

    // Child continues
    setsid();  // New session
    chdir("/"); // Root directory
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        // Daemon work
        sleep(10);
        // Could log to a file here
	printf("daemon process running ");
    }
}

int main() {
    create_daemon();
    return 0;
}

