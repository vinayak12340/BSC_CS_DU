#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {  
        // Child process code
        printf("I am the Child process (PID: %d)\n", getpid());
    } else {  
        // Parent process code
        wait(NULL);  // parent waits for child
        printf("I am the Parent process (PID: %d)\n", getpid());
    }

    return 0;
}