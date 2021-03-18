#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 4

void spiral(int A[n][m]){
	int left = 0;
	int right = m-1;
	int top = 0;
	int bottom = n-1; 
	int value = 1;
	
	int i, j = 0;
	while(left<=right && top<=bottom){
		for(j = left; j <= right; j++){
			A[top, j] = value;
			value++;
		}
		top++;
		if(top<=bottom){
			for(i=top; i<=bottom; i++){
				A[i,right] = value;
				value++;
			}
		}
		right--;
		if(left<=right){
			for(j=left; j<=right; j++){
				A[bottom, 
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
    int A[ROW][COL] = {0};
    spiral(A);
    printArray(A);
}
