#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int nt, it;
	
	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int p, k, l, i, j, t, f[1000];
		ll r = 0;
		
		cin >> p >> k >> l;
		for (i = 0; i < l; i++) cin >> f[i];
		
		sort(f, f + l);
		for (i = 1; i <= p; i++) {
			for (j = 0; j < k; j++) {
				if (l - ((i - 1) * k + j) - 1 >= 0) r += ll(f[l - ((i - 1) * k + j) - 1]) * i;
			}
		}
		
		cout << "Case #" << it << ": " << r << '\n';
	}
	
	return 0;
}
