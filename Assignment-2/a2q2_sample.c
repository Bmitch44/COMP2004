#include <stdio.h>
#include <stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000

struct node {
    int pid;
    struct node* next;
};

struct node* head = NULL;

// Function prototypes
void init_list(void);
int allocate_pid(void);
void release_pid(int pid);
int print_pid_list(void);

int main(){
    init_list(); 
    // one that allocates 100 PIDs, 
    for (int i = 0; i < 100; i++) {
        allocate_pid();
    }

    // one that prints the list,
    print_pid_list();

    // one that releases 50 PIDs,
    for (int i = MIN_PID; i < MIN_PID+50; i++) {
        release_pid(i);
    }

    // and one last that prints the list again.
    print_pid_list();
}

void init_list(void) {
    // intializes the list
    head = NULL;
}

int allocate_pid(void) {
    struct node* new_node = malloc(sizeof(struct node));

    // checks if list is empty
    if (head == NULL) {
        new_node->pid = MIN_PID;
        new_node->next = NULL;
        head = new_node;
        return new_node->pid;
    } else {
        struct node* temp = head;
        // loops through list to find the first available pid
        while (temp->next != NULL && temp->next->pid - temp->pid == 1) {
            temp = temp->next;
        }
        // checks if the last pid is the max pid
        if (temp->pid + 1 == MAX_PID) {
            return -1;
        }
        new_node->pid = temp->pid + 1;
        new_node->next = NULL;
        temp->next = new_node;
        return new_node->pid;
    }
}

void release_pid(int pid) {
    struct node* temp = head;

    // checks if head node is the one to be released
    if (temp != NULL && head->pid == pid) {
        head = temp->next;
        free(temp);
        return;
    }

    // checks if any other node is the one to be released
    while (temp->next != NULL && temp->next->pid != pid) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("PID %d not found\n", pid);
    } else {
        struct node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

int print_pid_list(void) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->pid);
        temp = temp->next;
    }
    return 0;
}