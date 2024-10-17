#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to handle the alert process
void SecuritySystemTrigger(const char *doorName) {
    pid_t pid = fork(); // Fork for the notification
    
    if (pid == 0) {
        printf("Child process (%s): NOTIFICATION\n", doorName);
        exit(0);
    } 
    else {
        printf("Parent process (%s): ALARM\n", doorName);
    }
}

int main() {
    // State of the door (0: closed, 1: open)
    char mainDoorOpened = 0; 
    char backDoorOpened = 0; 
    //State of security system (0: off, 1: on)
    char isArmed = 0;

    while (1) { // Infinite loop to continuously check the states
        
        printf("\n\nArm the security system? (1 for on, 0 for off): ");
        scanf(" %hhd", &isArmed);
        printf("\nEnter main door status (1 for open, 0 for closed): ");
        scanf(" %hhd", &mainDoorOpened);
        printf("Enter back door status (1 for open, 0 for closed): ");
        scanf(" %hhd", &backDoorOpened);

        if(isArmed){
            // Check the state and trigger alert if necessary
            if (mainDoorOpened) {
                SecuritySystemTrigger("main door");
            }
            if (backDoorOpened) {
                SecuritySystemTrigger("back door");
            }

            sleep(0.5); // delay to fix print formatting
        }
    }
    return 0;
}
