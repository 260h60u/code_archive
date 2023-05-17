#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for rand/srand
#include <time.h> //for time

void bubbleSort(int* A, int n) {
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				//A[j] <-> A[j+1]
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int n, i;
	int* A; //array를 위한 포인트 변수

	scanf("%d", &n);
	if (n <= 0) //error check
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL) //할당 실패
		return 0;

	srand(time(NULL)); //seed 값 현재시간으로 설정 , seed 값 달라짐 -> random 으로 나오는 값도 달라짐
	//srand(303); error를 재현할 때 (seed 고정)

	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	bubbleSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]); //정렬된 결과 출력

	free(A);//동적으로 할당된 A를 다 썼을 때
	return 0;
}