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

int main() {
	int N,A[100010],sign = 0,ans = 0;
	cin >> N;
	REP(i, N) { 
		cin >> A[i];
		if (i > 0) {
			if (A[i] - A[i - 1] > 0) {
				if (sign < 0) {
					ans++;
					sign = 0;
				}
				else if (sign == 0) {
					sign = 1;
				}
			}
			else if (A[i] - A[i - 1] < 0) {
				if (sign > 0) {
					ans++;
					sign = 0;
				}
				else if (sign == 0) {
					sign = -1;
				}
			}
		}
	}
	cout << ++ans << endl;
	return 0;
}