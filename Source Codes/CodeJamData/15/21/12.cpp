#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

int tc;
long long val;

long long reversenum(long long num) {
	long long h = 0;
	while (num > 0) {
		h = h * 10 + num % 10;
		num /= 10;
	}

	return h;
}

long long ans(long long val) {
	if (val <= 20)
		return val;
	long long h = val;
	int len = 0;
	while (h > 0) {
		len++;
		h /= 10;
	}

	long long pw = 1;
	for (int i = 0; i < (len + 1) / 2; i++)
		pw *= 10;

	long long hpw = 1;
	for (int i = 1; i < len; i++)
		hpw *= 10;

	if (val % pw == 0)
		return ans(val - 1) + 1;
	else {
		return (val % pw - 1) + reversenum(val / pw) + ans(hpw - 1) + 1 + (reversenum(val / pw) != 1);
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> val;

    	cout << "Case #" << tnum + 1 << ": " << ans(val) << endl;
    }

    return 0;
}