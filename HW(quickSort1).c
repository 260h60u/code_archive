#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
	int id;
	int korean;
	int english;
	int math;
};

int partition(struct Student* A, int p, int r)
{
	int i, j;
	struct Student t;

	i = p - 1;

	for (j = p; j < r; j++) {
		if (A[j].korean > A[r].korean) { //국어 성적으로  내림차순
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

int main() {
	int n, i;
	struct Student* A;

	scanf("%d", &n);
	if (n <= 0) //error check
		return 0;

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL) //할당 실패
		return 0;

	srand(time(NULL)); 

	for (i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].korean = rand() % 101;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
	}

	printf("id\tenglish\tmath\tkorean\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	quickSort(A, 0, n-1);

	printf("========================\n");
	printf("id\tenglish\tmath\tkorean\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].english, A[i].math, A[i].korean); //정렬된 결과 출력

	free(A);//동적으로 할당된 A를 다 썼을 때
	return 0;
}