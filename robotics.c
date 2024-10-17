#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Starting the robotics system.\n");

    pid_t pid = fork(); // Fork a new process for image processing

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } 
    else if (pid == 0) { 
        printf("Child process: Performing image processing for object recognition.\n");
        sleep(3); 
        printf("Child process: Image processing completed.\n");
        exit(0);
    } 
    else { 
        printf("Parent process: Waiting for image processing to complete...\n");
        wait(NULL); 
        printf("Parent process: Image processing complete.\n");

        // POST IMAGE PROCESSING ACTIONS
    }

    return 0;
}
