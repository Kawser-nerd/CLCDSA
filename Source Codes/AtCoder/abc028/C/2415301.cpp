#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>

using namespace std;
int main(void) {
	int list[25] = { 0 };
	int A[6] = { 0 };

	for (int i = 0; i < 5; i++)
		scanf("%d", &A[i]);

	int a = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				list[a++] = A[i] + A[j] + A[k];
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (list[i] < list[j]) {
				a = list[i];
				list[i] = list[j];
				list[j] = a;
			}
		}
	}

	printf("%d\n", list[2]);

	return 0;
}