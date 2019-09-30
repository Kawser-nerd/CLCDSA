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
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cout << s[i];
		}
	}
	cout << endl;


	return (0);
}