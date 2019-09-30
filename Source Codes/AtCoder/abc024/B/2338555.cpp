#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
#include <sstream>
#include <set>  

using namespace std;

int main()
{
	int N;
	int T;

	cin >> N >> T;
	int ans = 0;
	int now = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (i != 0) {
			if (A < now + T) {
				ans += A - now;
			}
			else {
				ans += T;
			}
		}
		now = A;
	}
	ans += T;

	cout << ans << endl;

	return 0;
}