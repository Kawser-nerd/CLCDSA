#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
string s;
long long solve(long long i) {
	long long ans = 0;
	long long chainer = 0;
	long long doing = 0;
	long long pro = (long long)s.length() - i;
	for (int q = i;q < (long long)s.length() - i;++q) {
		if (s[q] == '0') {
			if (doing == 1) {
				doing = 0;
				pro = min(pro, chainer);
				chainer = 0;
			}
		}
		else {
			doing = 1;
			chainer++;
		}
	}
	if (doing == 1) {
		doing = 0;
		pro = min(pro, chainer);
		chainer = 0;
	}
	ans = max(ans, pro);
	chainer = 0;
	doing = 0;
	pro = (long long)s.length() - i;
	for (int q = i;q < (long long)s.length() - i;++q) {
		if (s[q] == '1') {
			if (doing == 1) {
				doing = 0;
				pro = min(pro, chainer);
				chainer = 0;
			}
		}
		else {
			doing = 1;
			chainer++;
		}
	}
	if (doing == 1) {
		doing = 0;
		pro = min(pro, chainer);
		chainer = 0;
	}
	ans = max(ans, pro);
	return ans;
}
int main() {
#define int long long
	cin >> s;
	long long top = (long long)s.length(), bot = 0;
	while (top - bot > 2) {
		long long bott = (top+bot+bot)/3,topp = (top+top+bot)/3;
		if (solve(bott) <= solve(topp)) {
			bot = bott;
		}
		else top = topp;
	}
	long long ans = 0;
	for (int i = 0;i < 10;++i) {
		ans = max(ans, solve(bot + i));
	}
	cout << ans << endl;
	return 0;
}