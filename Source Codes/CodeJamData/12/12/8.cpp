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
    	int n;
    	cin >> n;
    	vector<int> a(n), b(n);
    	for (int i = 0; i < n; ++i)
    		cin >> a[i] >> b[i];
    	int res = 0;
    	vector<int> done(n);
    	int points = 0;
    	while (true) {
    		int to = -1;
    		bool all = true;
			for (int i = 0; i < n; ++i) {
				all &= done[i] == 2;
				if (done[i] < 2 && b[i] <= points) {
					to = i;
					break;
				} else if (done[i] < 1 && a[i] <= points) {
					if (to == -1 || b[to] < b[i])
						to = i;
				}
			}
			if (all)
				break;
			if (to == -1) {
				res = -1;
				break;
			}
			if (b[to] <= points) {
				points += 2 - done[to];
				done[to] = 2;
				++res;
			} else {
				assert(a[to] <= points);
				assert(done[to] == 0);
				points += 1;
				done[to] = 1;
				++res;
			}
    	}
    	if (res >= 0)
    		cout << "Case #" << testNumber << ": " << res << endl;
    	else
    		cout << "Case #" << testNumber << ": " << "Too Bad" << endl;
    }

    return 0;
}
