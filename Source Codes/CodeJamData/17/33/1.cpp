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

const int iters = 100;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;

    for (int tnum = 0; tnum < tc; tnum++) {
    	int n, k;
    	cin >> n >> k;
    	double u;
    	cin >> u;
    	vector <double> p(n);
    	for (int i = 0; i < n; i++)
    		cin >> p[i];

    	sort(p.begin(), p.end());

    	double ans = 0.0;
    	for (int i = 0; i < n; i++) {
	    	double lb = 0.0;
    		double rb = 1.0;
    		for (int it = 0; it < iters; it++) {
    			double mid = (lb + rb) / 2.0;
    			double sum = 0.0;
    			for (int j = i; j < n; j++)
    				sum += max(0.0, mid - p[j]);
    			if (sum > u)
    				rb = mid;
    			else
    				lb = mid;
    		}

    		double res = (lb + rb) / 2.0;
    		vector <double> np(n);
    		np = p; // Oh, yeah
    		double has = u;
			for (int j = i; j < n; j++) {
				np[j] = max(np[j], res);
				has -= np[j] - p[j];
			}
			int curp = i - 1;
			while (curp >= 0) {
				np[curp] = min(1.0, np[curp] + has);
				has -= np[curp] - p[curp];
				curp--;
			}

	   		vector <vector <double> > probs(n + 1, vector <double>(n + 1, 0.0));
	   		probs[0][0] = 1.0;
	   		for (int j = 0; j < n; j++)
	   			for (int h = 0; h < n; h++) {
	   				probs[j + 1][h + 1] += probs[j][h] * np[j];
	   				probs[j + 1][h] += probs[j][h] * (1 - np[j]);
	   			}
	   		double cur = 0.0;
	   		for (int j = k; j <= n; j++) {
	   			cur += probs[n][j];
//	   			cerr << tnum << ' ' << n << ' ' << j << ' ' << probs[n][j] << endl;
	   		}
	   		ans = max(ans, cur);
    	}
		cout.precision(20);
		cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}