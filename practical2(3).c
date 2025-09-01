#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        // Child executes a different program using exec
        printf("Child process replacing itself with 'ls -l' command:\n");
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        wait(NULL);  // wait for child to finish
        printf("Parent process finished after child.\n");
    }

    return 0;
}