#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<long> A(max(N,3));
	A[0] = 0; A[1] = 0; A[2] = 1;
	for (int i = 3; i < N; i++) {
		A[i] = (A[i - 3] + A[i - 2] + A[i - 1]) % 10007;
	}

	cout << A[N - 1] << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}