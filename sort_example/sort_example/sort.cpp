#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define N1 1000
#define N2 10000
#define N3 100000

using namespace std;

void Swap(int *src, int *dst) {

	int temp;

	temp = *src;
	*src = *dst;
	*dst = temp;
}

void init_Array(int Array[], int type, int Array_Size) {

	if (type == 0) { // random �� �ο�

		srand(time(NULL)); // ���� �ð��� ���� �ʱ�ȭ
		for (int i = 0; i < Array_Size; i++) {

			Array[i] = rand() % 1000; // 1000 ���� ���� ������ �ο�
		}
	}
	else if (type == 1) { // �Ųٷ� �� �� �ο�
		int i = 0;

		while (1) {

			if (Array_Size == i)
				break;
			Array[i] = Array_Size - i;
			i++;

		}
	}

	else {

		for (int i = 0; i < Array_Size; i++)
			Array[i] = 0;
	}
}
void Merge(int TD[], int p, int q, int r) { // ���ݺο� �Ĺݺθ� ���ļ� �ϳ��� ���ĵ� �迭�� �����Ѵ�.

	int i = p;
	int j = q + 1;
	int index = p;

	int buffer[N1];
	std::fill_n(buffer, N1, -1);

	while (i<=q && j <=r) {

		if (TD[i] < TD[j]) {
			buffer[index++] = TD[i++];
		}
		else {
			buffer[index++] = TD[j++];
		}
	}

	if (i >= q)
		while (j <= r)
			buffer[index++] = TD[j++];

	if (j >= r)
		while (i <= q)
			buffer[index++] = TD[i++];

	for (int k = p; k < r; k++) // �� 0���� �ϸ� �ȵ���..
		TD[k] = buffer[k];

}

void Merge_Sort(int TD[], int p, int r) { //p =0,  r -> N-1
	int q;
	if (r > p)
	{
		q = (p + r) / 2;
		// ���ݺ� ����
		Merge_Sort(TD, p, q);
		// �Ĺݺ� ����
		Merge_Sort(TD, q + 1, r);
		// �պ�
		Merge(TD, p, q, r);
	}

}


void Insertion_Sort(int TD[], int Array_Size) {


}

void Selection_Sort(int TD[], int Array_Size) {

	int pos = 0;
	int count = 0;
	int max = 0;

	for (int i = 0; i < Array_Size; i++) {
		max = 0;
		pos = 0;
		for (int j = 0; j < Array_Size - count; j++) {

			if (TD[j] > max) {
				pos = j;
				max = TD[j];
			}
		}

		Swap(&TD[Array_Size - (count + 1)], &TD[pos]);
		count++;

	}
}

void Bubble_Sort(int TD[], int Array_Size) {

	int count = 0;
	int temp = 0;

	for (int i = 0; i < Array_Size; i++) {

		for (int j = 0; j < Array_Size - count - 1; j++) {

			if (TD[j] > TD[j + 1])
				Swap(&TD[j], &TD[j + 1]);

		}
		count++;
	}
}
int partition(int TD[], int p, int r) { // pivot �� ��ġ�� �ڸ� return
	int i = p, j = p;
//	int pivot = TD[r]; last
//  int pivot = TD[rand() % r];
//  int pivot = TD[(p+r)/2];

	while (1) {

		if (TD[j] < TD[r])
		{
			Swap(&TD[i], &TD[j]);
			i++;
			j++;
		}
		else {

			j++;
		}
		
		if (j == r)
		{
			Swap(&TD[i], &TD[j]);
			break;
		}

	}

	return i;
}

void Quick_Sort(int TD[], int p, int r) { // last, mid, random pivot ������ ����

	int q = 0;
	if (p < r) {
		q = partition(TD, p, r);
		Quick_Sort(TD, p, q - 1);
		Quick_Sort(TD, q + 1, r);
	}
}

int Max_Heapify(int TD[], int root) { // recursion , iterative 2 �� 1 ��

	if (2 * root > 1000)
		return -1;
	if (TD[root] >= TD[2 * root] && TD[root] >= TD[2 * root + 1])
		return -1;
	if (TD[2 * root + 1] > TD[2 * root]) {
		Swap(&TD[root], &TD[2 * root + 1]);
		Max_Heapify(TD, 2 * root + 1);
	}
		
	else {
		Swap(&TD[root], &TD[2 * root]);
		Max_Heapify(TD, 2 * root);
	}
	return root;
}

void Heap_Sort(int TD[], int p, int r) {

	// ������ ���� ��ȸ.
	int p;
	int ch1, ch2;

	p = TD[(r - 1) / 2];
	ch1 = TD[r];
	ch2 = TD[r - 1];

	if (p < ch1 || p < ch2)
	{
		if (ch1 < ch2)
			Swap(&TD[(r - 1) / 2], &TD[r - 1]);
		else
			Swap(&TD[(r - 1) / 2], &TD[r]);
	}





	//root node A[1]
	//A[i] �� parent = A[i/2]
	// A[i] �� left child = A[2i]
	// A[i] �� right child = A[2i+1]
}

int main() {

	int TD1[N1], TD2[N2], TD3[N3];
	init_Array(TD1, 0, N1);
	init_Array(TD2, 0, N2);
	init_Array(TD3, 0, N3);

	//   Bubble_Sort(TD1, N1);
	//   Selection_Sort(TD1, N1);
	//	Merge_Sort(TD1, 0, N1 - 1);
	//	Quick_Sort(TD1, 0, N1 - 1);
	Heap_Sort(TD1, 0, N1 - 1);

	for (int i = 0; i < N1; i++) {
		printf("%d ", TD1[i]);
	}

	return 0;
}