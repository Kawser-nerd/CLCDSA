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

int r, c, n;
int tc;

int getvalue(int x, int y) {
	int val = 0;
	if (x > 0)
		val++;
	if (y > 0)
		val++;
	if (x < r - 1)
		val++;
	if (y < c - 1)
		val++;

	return val;	
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> r >> c >> n;

    	if ((r + 1) / 2 * (c + 1) / 2 >= n) {
    		cout << "Case #" << tnum + 1 << ": 0" << endl;
    	} else {
    		int ans2 = 0;
    		int hn = n;

    	for (int i = 0; i < r; i++)
    		for (int j = 0; j < c; j++) {
    			if ((i + j) % 2 == 0 && hn > 0) {
    				hn--;
    			}
    		}

    	for (int v = 1; v <= 4; v++)
    		for (int i = 0; i < r; i++)
    			for (int j = 0; j < c; j++)
    				if ((i + j) % 2 == 1 && hn > 0 && getvalue(i, j) == v) {
    					hn--;
    					ans2 += v;
    				}

       	

    		n = r * c - n;
    		int ans = r * (c - 1) + (r - 1) * c;

//    		cerr << r << ' ' << c << ' ' << n << ' ' << getvalue(1, 1) << endl;
    		for (int v = 4; v > 0; v--) {
    			for (int i = 0; i < r; i++)
    				for (int j = 0; j < c; j++) {
//    				    cerr << r << ' ' << c << ' ' << n << ' ' << v << ' ' << i << ' ' << j << ' ' << getvalue(i, j) << endl;
    					if (((i + j) % 2 == 0) && (n > 0) && (getvalue(i, j) == v)) {
    						n--;
    						ans -= v;

//    						cerr << v << ' ' << i << ' ' << j << endl;
    					}
    				}
    		}

    		cout << "Case #" << tnum + 1 << ": " << min(ans, ans2) << endl;
       	
    	}

    	
    	
    }

    return 0;
}