#include <stdio.h>
#include <stdlib.h>

void buildList(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		A[i] = i + 1;
	}
	return;
}


//ver1
int runSimulation1(int A[], int n, int k)
{
	int r = 0;
	int N = n;
	while (n > 1) {
		int i = 0;
		while (i < k) {
			r = (r + 1) % N;
			if (A[r] != 0) {
				i++;
			}
		}
		A[r] = 0;
		n -= 1;
		while (A[r] == 0) {
			r = (r + 1) % N;
		}
	}
	return A[r];

}
int removed(int A[], int n, int pos)
{
	int i;
	for (i = pos; i < n; i++) {
		A[i] = A[i + 1];
	}
	return A;
}

//ver2
int runSimulation2(int A[], int n, int k) {
	int r = 0;
	while (n > 1) {
		r = (r + k) % n;
		removed(A,n,r);
		n--;
	}
	return A[0];
}

int candle(int n, int k)
{
	int* A = malloc(sizeof(int) * n);
	buildList(A, n);
	return runSimulation2(A, n, k);
}


int main(void) {
	int n,k;
	scanf("%d %d", &n, &k);
	candle(n,k);
}
