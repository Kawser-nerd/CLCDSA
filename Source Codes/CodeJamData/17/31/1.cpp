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

const double pi = acos(-1.0);

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	int n, k;
    	cin >> n >> k;
    	vector <pair <int, int> > pans;
    	for (int i = 0; i < n; i++) {
    		int r, h;
    		cin >> r >> h;
    		pans.pb(mp(r, h));
    	}

    	double ans = 0.0;
    	for (int i = 0; i < n; i++) {
    		int mr = pans[i].fs;
    		
    		vector <double> vol;
    		for (int j = 0; j < n; j++) {
    			if (j != i && pans[j].fs <= mr) {
    				vol.pb(2 * pi * pans[j].fs * 1.0 * pans[j].sc);
    			}
    		}

    		sort(vol.rbegin(), vol.rend());
    		if ((int) vol.size() >= k - 1) {
    			double sum = pi * mr * 1.0 * mr + 2 * pi * pans[i].fs * 1.0 * pans[i].sc;
    			for (int j = 0; j < k - 1; j++)
    				sum += vol[j];

    			ans = max(ans, sum);
    		}
    	}

    	cout.precision(20);
    	cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}