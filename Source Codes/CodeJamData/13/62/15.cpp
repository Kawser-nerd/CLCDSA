#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef long long Int;
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }

int T[50050];

void solve()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
    	cin >> T[i];
    }
    
    double lo = 0.0, hi = 5e5;
    for (int i = 0; i < 50; ++i) {
    	double mid = (hi + lo) / 2;
    	
    	for (int j = 0; j < N; ++j) {
    		for (int side = -1; side <= 1; side += 2) {
				double jpos = T[j] + side * mid;
				double lb = 0, ub = 1e9;
				for (int k = 0; k < j; ++k) {
					chmax(lb, (T[k] + mid - jpos) / (k - j));
					chmin(ub, (T[k] - mid - jpos) / (k - j));
				}
				for (int k = j + 1; k < N; ++k) {
					chmax(lb, (T[k] - mid - jpos) / (k - j));
					chmin(ub, (T[k] + mid - jpos) / (k - j));
				}
				if (lb <= ub) {
					hi = mid;
					goto next;	
				}
			}
    	}
    	lo = mid;
    	next:;
	}
	
	printf("%.9f\n", hi);
}

int main()
{
    int CASES;
    cin >> CASES;
    
    for (int CASE = 1; CASE <= CASES; ++CASE) {
        cout << "Case #" << CASE << ": ";
        solve();   
    }
    
    return 0;
}


