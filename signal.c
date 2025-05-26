#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_sigint(int sig) {
    printf("\n🛑 Caught signal %d (SIGINT). Cleaning up and exiting...\n", sig);
    exit(0);  // Exit gracefully
}

int main() {
    // Register the signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    printf("Process running with PID: %d\n", getpid());
    printf("Press Ctrl+C to send SIGINT...\n");

    // Infinite loop to keep the process alive
    while (1) {
        printf("Working...\n");
        sleep(2);
    }

    return 0;
}

