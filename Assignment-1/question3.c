#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    char *filename = "sensor.csv";
    int *csv_to_arr(char *filename); // Declare the function
    int *array = csv_to_arr(filename);
    void print_stats(int *array); // Declare the function
    print_stats(array);
    free(array); // Free the memory allocated for the array
    return 0; // Add the missing semicolon
}

// The function will take csv file and return an array of integers
int *csv_to_arr(char *filename) {
    // open file and check if it exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file");
        return NULL;
    }

    // create the array to store the values
    int *array = malloc(5 * sizeof(int)); // Allocate memory for the array

    int index = 0;
    int num;

    // read the file and store the values in the array
    while (fscanf(file, "%d\n", &num) > 0) {
        array[index] = num;
        index++;
    }

    fclose(file);
    return array;
}

// The function will take an array of integers and print the stats
void print_stats(int *array) {
    int count = 0;
    int sum = 0;
    float mean = 0.0f;
    float variance = 0.0f;
    float std_deviation = 0.0f;
    
    // calculate the stats
    for (int i = 0; i < 5; i++) {
        count++;
        sum += array[i];
    }
    mean = (float)sum / count;

    for (int i = 0; i < 5; i++) {
        variance += (array[i] - mean) * (array[i] - mean);
    }
    variance = variance / count;
    std_deviation = sqrt(variance);

    // print the stats
    printf("Count: %d\n", count);
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", std_deviation);
}