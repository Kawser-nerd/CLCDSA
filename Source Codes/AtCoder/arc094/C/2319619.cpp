#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int failed = 1;
	vector<long long> geko;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		long long a, b;
		cin >> a >> b;
		if (a != b) failed = 0;
		else ans += a;
		if (a < b) ans += b;
		else if (a != b) geko.push_back(b);
	}
	sort(geko.begin(), geko.end(),greater<long long>());
	if (failed == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < geko.size() - 1; ++i) {
		ans += geko[i];
	}
	cout << ans << endl;
	return 0;
}