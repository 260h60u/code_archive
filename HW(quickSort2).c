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

int partition(struct Student* A, int p, int r, int key)
{
	int i, j;
	struct Student t;

	i = p - 1;

	if (key == 1) {
		for (j = p; j < r; j++) {
			if (A[j].korean > A[r].korean) { //국어 성적으로  내림차순
				i++;
				//A[i] <-> A[j]
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	else if (key == 2) {
		for (j = p; j < r; j++) {
			if (A[j].math > A[r].math) { //수학 성적으로  내림차순
				i++;
				//A[i] <-> A[j]
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	else if (key == 3) {
		for (j = p; j < r; j++) {
			if (A[j].english > A[r].english) { //영어 성적으로  내림차순
				i++;
				//A[i] <-> A[j]
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	else if (key == 4) {
		for (j = p; j < r; j++) {
			if (A[j].id < A[r].id) { //id 기준으로 오름차순
				i++;
				//A[i] <-> A[j]
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}

	i++;
	t = A[i];
	A[i] = A[r];
	A[r] = t;
	return i;
}

void quickSort(int* A, int p, int r, int key)
{
	if (p < r) {
		int q = partition(A, p, r, key);
		quickSort(A, p, q - 1, key);
		quickSort(A, q + 1, r, key);
	}
}

int main() {
	int n, i, key;
	struct Student* A;

	printf("학생 수를 입력하세요 : ");
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

	for (i = 0; i < n; i++) {
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\t\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
	printf("\n");

	do {
		printf("정렬 기준 선택<1: 국어, 2: 수학, 3: 영어, 4: id<오름차순>, 0: 끝내기> : ");
		scanf("%d", &key);

		if (key == 0)
			break;
		else {
			quickSort(A, 0, n - 1, key);
			for (i = 0; i < n; i++) {
				printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\t\n", A[i].id, A[i].english, A[i].math, A[i].korean);
			}
			printf("\n");
		}

	} while (key != 0);


	free(A);

	return 0;
}