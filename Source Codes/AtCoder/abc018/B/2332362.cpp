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
	string s, t;
	int n, l, r;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		t = s.substr(l-1, r-l+1);
		std::reverse(t.begin(), t.end());
		s.replace(l-1, r-l+1,t);
	}
	cout << s << endl;

	return 0;
}