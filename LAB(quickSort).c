#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r)
{
	int i, j;
	int t;

	i = p - 1;

	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			//A[i] <-> A[j]
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	i++;
	t = A[i];
	A[i] = A[r];
	A[r] = t;
	return i;
}

void quickSort(int* A, int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void)
{
	int* A;
	int i, n;

	scanf("%d", &n);

	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	printList(A, 0, n - 1);

	quickSort(A, 0, n - 1);

	printList(A, 0, n - 1);

	free(A);
	return 0;
}