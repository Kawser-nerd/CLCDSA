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
	cout.precision(12);
	cout << fixed;
	
	int T;
	cin >> T;   	
	for (int __it =0; __it < T; __it++) {
		int k, l, s;
		string kbd, target;
		cin >> k >> l >> s;

		cin >> kbd;
		cin >> target;

		vector<double> prk(26);
		for (int i = 0; i < (int)kbd.length(); ++i) {
			prk[kbd[i] - 'A']++;
		}
		for (int i = 0; i < 26; ++i) prk[i] /= k;

		bool fail = 0;
		for (int i = 0; i < target.length(); ++i)
			if (prk[target[i] - 'A'] == 0) {
				fail = 1;
				break;
			}
		if (fail) {
			cout << "Case #" << (__it+1) << ": " << 0 << endl;			
			continue;
		}
				

		int maxans = s / l;
		if (s > l)
			for (int i = 1; i < (int)target.length(); ++i) {
				if (target.substr(i) == target.substr(0, target.length() - i)) {
					maxans = ((s - l) / i) + 1;
					break;
				}
			}

		vector<int> p(l);
//		cerr << 0 << " ";
		for (int i = 1; i < l; ++i) {
			int k = p[i - 1];
			while (k > 0 && target[k] != target[i]) k = p[k-1];
			if (target[k] == target[i]) ++k;else k = 0;
			p[i] = k;
//			cerr << p[i] << " ";
		}
//		cerr << endl;

		double sum = 0;
		vector<double> pr(l+1, 0);
		pr[0] = 1;

		for (int i = 0; i < s; ++i) {
			vector<double> pr2(l+1, 0);
			for (int j = 0; j <= l; ++j) {
				for (int c = 0; c < 26; ++c) {
					int cur = j;
					while (cur > 0 && target[cur] - 'A' != c) {
						cur = p[cur-1];
                    }
                    if (target[cur] - 'A' == c) ++cur;else cur = 0;
					pr2[cur] += pr[j] * prk[c];
				}
			}				
			pr = pr2;

//			for (int j = 0; j <= l; ++j)
//				cerr << pr[j] << " ";
//			cerr << endl;
			sum += pr[l];
		}

		cout << "Case #" << (__it+1) << ": " << maxans - sum << endl;
	}
    
    return 0;
}
