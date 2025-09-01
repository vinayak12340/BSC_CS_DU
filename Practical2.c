#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // create a child process

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    // Both parent and child will execute this code
    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());

    if (pid > 0) {  
        // Parent waits for child to finish
        wait(NULL);
        printf("Parent finished.\n");
    } else {
        printf("Child finished.\n");
    }

    return 0;
}