#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000;

int tc, n;
long long d[size], h[size], m[size];

long long tryspeed(long long rt) {
	long long sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < h[i]; j++) {
			long long c = (m[i] + 720 * j) * d[i];
			if (rt <= c)
				sum++;
			else {
				sum += (rt - c) / (360 * (m[i] + 720 * j));
			}
		}

	cerr << rt << ' ' << sum << endl;

	return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cerr << tnum << endl;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> d[i] >> h[i] >> m[i];
    		d[i] = 360 - d[i];

    		m[i] *= 720;
    	}

    	long long sum = 0;
    	long long ans = 0;
    	for (int i = 0; i < n; i++)
    		sum += h[i];
    	ans = sum;

    	vector <long long> cs;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < h[i]; j++) {
    			cs.pb((m[i] + 720 * j) * d[i]);
    		}
        sort(cs.begin(), cs.end());

        long long passed = 0;
        long long toadd = 0;
        set <pair <pair <long long, int>, pair <int, int> > > events;
        for (int i = 0; i < n; i++)
        	for (int j = 0; j < h[i]; j++) {
        		events.insert(mp(mp((m[i] + 720 * j) * d[i] + (360 * (m[i] + 720 * j)), 1), mp(i, j)));
        	}

        for (int i = 0; i < (int) cs.size(); i++) {
        	passed++;
        	while (toadd < sum && events.begin()->fs.fs <= cs[i]) {
        		toadd++;
        		long long rnum = events.begin()->fs.sc;
        		int g = events.begin()->sc.fs;
        		int gn = events.begin()->sc.sc;

        		events.erase(events.begin());
        		events.insert(mp(mp((m[g] + 720 * gn) * d[g] + (360 * (m[g] + 720 * gn)) * (rnum + 1), rnum + 1), mp(g, gn)));
        	}

        	ans = min(ans, sum - passed + toadd);
        }

//    	for (int i = 0; i < n; i++)
  //  		for (int j = 0; j < h[i]; j++) {
    //			ans = min(ans, tryspeed((m[i] + 720 * j) * d[i] + 1));
    //		}

    	cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}