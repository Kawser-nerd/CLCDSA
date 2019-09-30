#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 60 * 24;
const int inf = 1000 * 1000 * 1000;

int dp[2][size + 1][size + 1];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	int ac, aj;
    	cin >> ac >> aj;
    	vector <vector <bool> > busy(2, vector <bool>(size + 1, false));
    	for (int i = 0; i < ac; i++) {
    		int lb, rb;
    		cin >> lb >> rb;
    		for (int j = lb; j < rb; j++)
    			busy[0][j] = true;
    	}
    	for (int i = 0; i < aj; i++) {
    		int lb, rb;
    		cin >> lb >> rb;
    		for (int j = lb; j < rb; j++)
    			busy[1][j] = true;
    	}

    	int ans = size;
    	for (int charge = 0; charge < 2; charge++) {
    		for (int i = 0; i < 2; i++)
    			for (int j = 0; j <= size; j++)
    				for (int k = 0; k <= size; k++) {
    					dp[i][j][k] = inf;
    				}
    		dp[charge][0][0] = 0;
    		for (int i = 0; i < size; i++)
    			for (int j = 0; j < size; j++)
    				for (int p = 0; p < 2; p++) {
    					if (!busy[p][i]) {
    						dp[p][i + 1][j + (p == 0)] = min(dp[p][i + 1][j + (p == 0)], dp[p][i][j]);
    					}
    					if (!busy[1 - p][i]) {
    						dp[1 - p][i + 1][j + (p == 1)] = min(dp[1 - p][i + 1][j + (p == 1)], dp[p][i][j] + 1);
    					}
    				}

    		 ans = min(ans, min(dp[charge][size][size / 2], dp[1 - charge][size][size / 2] + 1));
    	}

    	cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}