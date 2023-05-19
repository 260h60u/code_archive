#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int english;
	int math;
	int korean;
};

void selectionSort(struct Student* A, int n) {
	int i, j, max, max_idx;
	struct Student temp;

	for (i = 0; i < n - 1; i++) {
		max = A[0].korean;
		max_idx = 0;

		for (j = 1; j < n - i; j++) { 
			if (max > A[j].korean) { //< 오름차순
				max = A[j].korean;
				max_idx = j;
			}
		}
		temp = A[n - 1 - i];
		A[n - 1 - i] = A[max_idx];
		A[max_idx] = temp;
	}
}

int main()
{
	int n, i;
	struct Student* A;

	scanf("%d", &n);
	if (n <= 0) {
		return 0;
	}

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL) {
		return 0;
	}
	
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
		A[i].korean = rand() %101;
	}

	printf("id\tenglish\tmath\tkorean\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
	printf("------------------------\n");

	selectionSort(A, n);

	printf("id\tenglish\tmath\tkorean\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}

	free(A);

	return 0;

}