#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //for rand/srand
#include <time.h> //for time

void insertionSort(int* A, int n) {
	int i, j, k;
	int tmp;

	for (i = 1; i < n; i++) {
		//insert A[i] to A[0...i-1]
		for (j = 0; j < i; j++) { //�� �ձ��� ��
			if (A[i] < A[j]) //(��) A[i]���� ū �ָ� ���ʷ� ������ break
				break; //inner loop Ż��
		}
		//j <-A[i]�� �� ��ġ�� ��
		tmp = A[i];
		//movement <�ּ�ó�� �����ؾ���>
		//A[j] = A[i-1];
		//A[i-1] = A[i-2];
		//A[i-2] = A[i-3];
		//..
		//A[j+1] = A[j] <�򰥸��� �ۼ��غ��� �ڵ�� �Űܺ���>
		for (k = i; k > j; k--) {
			A[k] = A[k - 1]; //k�� j+1�϶��� ������
		}

		A[j] = tmp;
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

	insertionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]); //���ĵ� ��� ���

	free(A);//�������� �Ҵ�� A�� �� ���� ��
	return 0;
}