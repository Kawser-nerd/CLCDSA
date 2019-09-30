#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
    	int k, n;
    	cin >> k >> n;
    	vector<double> p(k);
    	for (int i = 0; i < k; ++i)
    		cin >> p[i];
    	double res = n + 2;
    	double pcorrect = 1.0;
    	for (int i = 0; i <= k; ++i) {
    		if (i > 0)
    			pcorrect *= p[i - 1];
    		double r = 2 * (k - i) + n - k + 1;
    		r = pcorrect * r + (1 - pcorrect) * (r + n + 1);
    		res = min(r, res);
    	}
    	printf("Case #%d: %.6lf\n", testNumber, res);
        //cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
