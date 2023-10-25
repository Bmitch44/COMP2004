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
    for (int i = 0; i < num_elements; i++) {
        average += numbers[i];
    }
    average = average / num_elements;
    pthread_exit(0);
}

void *calculate_minimum(void *param) {
    // TODO 2: Implement the logic to calculate minimum
    minimum = numbers[0];
    for (int i = 0; i < num_elements; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    pthread_exit(0);
}

void *calculate_maximum(void *param) {
    // TODO 3: Implement the logic to calculate maximum
    maximum = numbers[0];
    for (int i = 0; i < num_elements; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    pthread_exit(0);
}

int main() {
    read_input();

    pthread_t threads[NUM_THREADS];
    // TODO 4: Create the threads and associate them with their respective functions
    for (int i = 0; i < NUM_THREADS; i++) {
        // create 3 different threads, each executing a different function
        if (i == 0) {
            pthread_create(&threads[i], NULL, calculate_average, NULL);
        } else if (i == 1) {
            pthread_create(&threads[i], NULL, calculate_minimum, NULL);
        } else {
            pthread_create(&threads[i], NULL, calculate_maximum, NULL);
        }   
    }
    // TODO 5: Wait for the threads to complete using pthread_join
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The average value is %d\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

    free(numbers);

    return 0;
}
