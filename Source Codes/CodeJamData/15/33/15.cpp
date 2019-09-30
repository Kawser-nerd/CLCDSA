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

typedef long long ll;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	int T;
	cin >> T;   	
	for (int __it =0; __it < T; __it++) {
		int c, d, v;
		cin >> c >> d >> v;
		vector<ll> a(d);
		for (int i = 0; i < d; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll sum = 0;
		int ans = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (sum >= v) {
				break;
			}
			while (a[i] > sum + 1) {
				ll x = sum + 1;
				sum += x * c;
				++ans;
			}
			sum += a[i] * c;
		}
		while (sum < v) {
			ll x = sum + 1;
			sum += x * c;
			++ans;			
		}
		cout << "Case #" << (__it+1) << ": " << ans << endl;
	}
    
    return 0;
}
