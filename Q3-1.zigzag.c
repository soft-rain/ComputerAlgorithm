#include <stdio.h>

#include <stdlib.h>

#define SIZE 5

void zigzag(int A[][SIZE]) {
    int value = 1;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < SIZE; j++) {
                A[i][j] = value;
                value++;
            } 
          }else {
                for (j = SIZE - 1; j >= 0; j--) {
                    A[i][j] = value;
                    value++;
                }
            }
        }
    }

void printArray(int A[][SIZE]) {
	int i, j;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++)
                printf("%2d ", A[i][j]);
              printf("\n");
        }
    }
   
int main() {
    int A[SIZE][SIZE] = {0};
    zigzag(A);
    printArray(A);
}
