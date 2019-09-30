#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	int T;
	cin >> T;   	
	for (int __it =0; __it < T; __it++) {
		int n, m, w;
		cin >> n >> m >> w;

		int ans = (n - 1) * (m / w);
		if (m % w == 0) {
			ans += (m / w - 1) + w;
		} else {
			ans += (m / w - 1) + w + 1;
		}
		cout << "Case #" << (__it+1) << ": " << ans << endl;
	}
    
    return 0;
}
