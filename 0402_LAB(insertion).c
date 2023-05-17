#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for rand/srand
#include <time.h> //for time

void insertionSort(int* A, int n) {
	int i, j, k;
	int tmp;

	for (i = 1; i < n; i++) {
		//insert A[i] to A[0...i-1]
		for (j = 0; j < i; j++) { //내 앞까지 비교
			if (A[i] < A[j]) //(나) A[i]보다 큰 애를 최초로 만나면 break
				break; //inner loop 탈출
		}
		//j <-A[i]가 들어갈 위치가 됨
		tmp = A[i];
		//movement <주석처럼 동작해야함>
		//A[j] = A[i-1];
		//A[i-1] = A[i-2];
		//A[i-2] = A[i-3];
		//..
		//A[j+1] = A[j] <헷갈리면 작성해보고 코드로 옮겨보기>
		for (k = i; k > j; k--) {
			A[k] = A[k - 1]; //k가 j+1일때가 마지막
		}

		A[j] = tmp;
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

	insertionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]); //정렬된 결과 출력

	free(A);//동적으로 할당된 A를 다 썼을 때
	return 0;
}