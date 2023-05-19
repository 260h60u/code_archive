#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* A, int p, int q, int r, int* temp)
{
	int i, j, t;

	i = p;
	j = q + 1;
	t = p;

	while (i <= q && j <= r) {
		if (A[i] < A[j]) {
			temp[t] = A[i];
			t++; i++;
		}
		else {
			temp[t] = A[j];
			t++; j++;
		}
	}

	if (j > r) {
		for (; i <= q; i++, t++)
			temp[t] = A[i];
	}
	else {
		for (; j <= r; j++, t++)
			temp[t] = A[j];
	}

	for (i = p; i <= r; i++)
		A[i] = temp[i];

}
void mergeSort(int A[], int p, int r, int* temp) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q, temp);
		mergeSort(A, q + 1, r, temp);
		merge(A, p, q, r, temp);
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
	int* temp;
	int i, n;

	scanf("%d", &n);
	if (n <= 0) {
		return 0;
	}

	A = (int*)malloc(sizeof(int) * n);
	temp = (int*)malloc(sizeof(int) * n);

	if (A==NULL || temp == NULL) {
		return 0;
	}

	srand(time(NULL));
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	printList(A, 0, n-1);

	mergeSort(A, 0, n - 1, temp);

	printList(A, 0, n-1);

	free(temp);
	free(A);

	return 0;
}