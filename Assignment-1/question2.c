#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // check if there is an argument
    if (argc != 2) {
        printf("No arguments given");
        return 1;
    }

    // convert the argument to an int
    int num = atoi(argv[1]);
    int table[num][num];

    // print the table header
    printf("Multiplication table for Z%d:\n", num);

    // print the top row
    printf("  ");
    for (int i = 0; i < num; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // print the table
    for (int i = 0; i < num; i++) {
        printf("%d ", i); // print the side column
        for (int j = 0; j < num; j++){
            table[i][j] = (i * j)%num;
            printf("%d ", table[i][j]);
            if (j == num - 1) {
                printf("\n");
            }
        }
    }
    return 0;
}
