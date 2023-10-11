#include <stdio.h>

#define MIN_PID 300
#define MAX_PID 5000

// Function prototypes
void init_list(void);
int allocate_pid(void);
void release_pid(int pid);
int print_pid_list(void);

int main(){
    init_list();
    // Create a loop that allocates a number of pids
    // Release some of the allocated pids
    // You may write and use the print_pid_list() to show your list working

    // To test your implementation, create four loops in your program's main function: 
    // one that allocates 100 PIDs, 
    // one that prints the list, 
    // one that releases 50 PIDs, 
    // and one last that prints the list again.
    // You can also modify the MIN_PID and MAX_PID value to test your program works as expected
}

void init_list(void) {
    // Implement initialization logic
}

int allocate_pid(void) {
    // Implement PID allocation logic
    // Return -1 if all PIDs are in use
}

void release_pid(int pid) {
    // Implement PID release logic
}

int print_pid_list(void) {
    // Implement PID list print logic
}