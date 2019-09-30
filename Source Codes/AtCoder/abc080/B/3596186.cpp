#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

// ???????????
int findSumOfDigits(int n) {
	if (n < 10)return n;
	return findSumOfDigits(n / 10) + n % 10;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << (N%findSumOfDigits(N)==0?"Yes":"No") << endl;
	return 0;
}