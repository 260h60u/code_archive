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
	int* A; //array�� ���� ����Ʈ ����

	scanf("%d", &n);
	if (n <= 0) //error check
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL) //�Ҵ� ����
		return 0;

	srand(time(NULL)); //seed �� ����ð����� ���� , seed �� �޶��� -> random ���� ������ ���� �޶���
	//srand(303); error�� ������ �� (seed ����)

	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	bubbleSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]); //���ĵ� ��� ���

	free(A);//�������� �Ҵ�� A�� �� ���� ��
	return 0;
}