#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int func(long long n) {
	if (n < 10)return 1;
	return func(n/10)+1;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A,B,C;
	bool found = false;
	scanf("%d %d %d", &A, &B, &C);
	for (int i = 1; i <= B; i++) {
		if (A * i % B == C) {
			found = true; 
			break;
		}
	}

	cout << (found?"YES":"NO") << endl;
	return 0;
}