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
using namespace std;

int main()
{
	int n, a, b, k, p;
	vector<int> q;

	cin >> n >> a >> b >> k;

	for (int i = 0; i < k; i++) {
		cin >> p;
		q.push_back(p);
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				if (p == q[j]) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}

		if (a == p || b == p) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}