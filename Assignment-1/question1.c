#include <stdio.h>

int main(void) {
    // define the values of n
    int n_vals[] = {5, 10, 27, 100};

    for (int i = 0; i < 4; i++) {
        int n = n_vals[i];

        for (int j = 0; j < 100; j++) {
            printf("%d, ", j%n);
        }
    printf("\n\n");
    }
}