#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1010
int n; double a[N], b[N]; bool v[N]; 

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n; 
		for (int i = 0; i < n; i ++) cin >> a[i]; 
		for (int i = 0; i < n; i ++) cin >> b[i]; 
		sort(a, a+n); 
		sort(b, b+n); 
		int s = 0; 
		int l = 0, r = n-1; 
		for (int i = 0; i < n; i ++) {
			if (a[i] > b[l]) {
				s ++; l ++; 
			} else {
				r --; 
			}
		}
		int t = 0; 
		l = 0, r = n-1; 
		for (int i = n-1; i >= 0; i --) {
			if (a[i] > b[r]) {
				t ++; l ++; 
			} else {
				r --; 
			}
		}
		printf ("Case #%d: %d %d\n", __, s, t); 
	}
	return 0; 
}