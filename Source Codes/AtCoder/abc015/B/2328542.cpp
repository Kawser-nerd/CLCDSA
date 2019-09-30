#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
using namespace std;

int main()
{
	double ans = 0;
	double num = 0;
	double N, A, S;
	cin >> N;
	S = N;

	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A == 0) {
			S -= 1;
		}
		num += A;
	}
	ans = std::ceil(num / S);
	cout << ans << endl;

	return 0;
}