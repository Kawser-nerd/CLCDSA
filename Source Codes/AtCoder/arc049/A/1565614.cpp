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
#define INF INT_MAX
#define ll long long

int main()
{
	string s;
	int a, b, c, d;
	cin >> s;
	cin >> a >> b >> c >> d;

	for (int i = 0; i < s.size(); i++) {
		if (i == a) {
			cout << "\"";
		}
		if (i == b) {
			cout << "\"";
		}
		if (i == c) {
			cout << "\"";
		}
		if (i == d) {
			cout << "\"";
		}
		cout << s[i];
	}
	if (d == s.size()) {
		cout << "\"";
	}
	cout << endl;

	return (0);
}