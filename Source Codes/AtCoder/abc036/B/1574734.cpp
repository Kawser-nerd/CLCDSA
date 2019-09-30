#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>


using namespace std;

#define MOD 1000000007
#define INF 2147483647
#define ll long long


int main()
{
	int n;
	cin >> n;
	vector<string> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= 0; j--) {
			cout << s[j][i];
		}
		cout << endl;
	}

	return (0);
}