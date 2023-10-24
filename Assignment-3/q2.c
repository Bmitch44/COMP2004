#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

int *numbers;
int num_elements;
int average;
int minimum;
int maximum;

// Function to read numbers from input.txt and populate the numbers array
void read_input() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Failed to open input.txt");
        exit(1);
    }

    int capacity = 10;  // initial capacity
    numbers = (int *)malloc(capacity * sizeof(int));
    num_elements = 0;

    while (fscanf(fp, "%d", &numbers[num_elements]) != EOF) {
        num_elements++;
        if (num_elements == capacity) {
            capacity *= 2;
            numbers = (int *)realloc(numbers, capacity * sizeof(int));
        }
    }

    fclose(fp);
}

void *calculate_average(void *param) {
    // TODO 1: Implement the logic to calculate average
    pthread_exit(0);
}

void *calculate_minimum(void *param) {
    // TODO 2: Implement the logic to calculate minimum
    pthread_exit(0);
}

void *calculate_maximum(void *param) {
    // TODO 3: Implement the logic to calculate maximum
    pthread_exit(0);
}

int main() {
    read_input();

    pthread_t threads[NUM_THREADS];
    // TODO 4: Create the threads and associate them with their respective functions

    // TODO 5: Wait for the threads to complete using pthread_join

    printf("The average value is %d\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

    free(numbers);

    return 0;
}
