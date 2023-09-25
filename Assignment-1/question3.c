#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read data from a CSV file and return an array of integers
int *csv_to_arr(char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    int *array = NULL; // Initialize the array as NULL
    int num;
    *size = 0; // Initialize the size to 0

    while (fscanf(file, "%d\n", &num) == 1) {
        (*size)++; // Increment the size for each value
        array = realloc(array, *size * sizeof(int)); // Dynamically allocate memory
        if (array == NULL) {
            printf("Memory allocation failed\n");
            fclose(file);
            return NULL;
        }
        array[*size - 1] = num; // Store the value in the array
    }

    fclose(file);
    return array;
}

// Function to calculate and print statistics
void print_stats(int *array, int size) {
    if (size == 0) {
        printf("No data to calculate statistics\n");
        return;
    }

    int count = size;
    int sum = 0;
    float mean = 0.0f;
    float variance = 0.0f;
    float std_deviation = 0.0f;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    mean = (float)sum / count;

    for (int i = 0; i < size; i++) {
        variance += (array[i] - mean) * (array[i] - mean);
    }
    variance = variance / count;
    std_deviation = sqrt(variance);

    printf("Count: %d\n", count);
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", std_deviation);
}

int main(void) {
    char *filename = "sensor.csv";
    int size;
    int *array = csv_to_arr(filename, &size);

    if (array != NULL) {
        print_stats(array, size);
        free(array);
    }

    return 0;
}
