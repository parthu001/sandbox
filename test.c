// Save as volatile_example.c
// Compile: gcc -pthread volatile_example.c -o volatile_example

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

volatile int flag = 0;

void* set_flag(void* arg) {
    sleep(2); // Simulate delay
    flag = 1; // Change the volatile variable
    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, set_flag, NULL);

    printf("Waiting for volatile flag to change...\n");

    // Loop until volatile variable changes
    while (flag == 0);

    printf("Detected change in volatile variable: flag = %d\n", flag);

    pthread_join(tid, NULL);
    return 0;
}

