#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#define REP(i,n) for(int i=0;i<n;i++)
#define maxi(a,b) (((a) > (b)) ? (a) : (b))
#define mini(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/********************************************************/
	int n, q;

	cin >> n >> q;
	vector<int> v(n,0);

	int l, r;
	REP(i, q) {
		cin >> l >> r;
		v[l - 1] += 1;
		if (r < n) {
			v[r] -= 1;
		}
	}

	int s = 0;
	REP(i, n) {
		s += v[i];
		cout << s % 2;
	}
	cout << endl;


	/********************************************************/
	int ret_ = 0;
	return 0;
}