#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include <typeinfo>
#include <stdlib.h>
#define ll long long
const int MOD = 1000000007;
using namespace std;

int main() {
	string s;
	int t, count = 0, x = 0, y = 0;
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '?') count++;
		if (s[i] == 'L')x -= 1;
		if (s[i] == 'R')x += 1;
		if (s[i] == 'U')y += 1;
		if (s[i] == 'D')y -= 1;
	}
	if (t == 1) {
		cout << abs(x) + abs(y) + count << endl;
	} else {
		if (count <= abs(x) + abs(y)) {
			cout << abs(x) + abs(y) - count << endl;
		} else if ((count - abs(x) - abs(y)) % 2 == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}