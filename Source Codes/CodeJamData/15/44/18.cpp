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
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};
const int size = 100;

int clr[size][size];
int r, c;

bool onfield(int x, int y) {
	return (x >= 0 && y >= 0 && x < r && y < c);
}

bool isvalid(int x, int y) {
	if (clr[x][y] == -1)
		return true;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
	    int tx = x + px[i];
	    int ty = (y + py[i] + c) % c;
	    if (!onfield(tx, ty))
	    	continue;
	    if (clr[tx][ty] == -1)
	    	return true;
		cnt += clr[tx][ty] == clr[x][y]; 
	}

	return (cnt == clr[x][y]);
}

set <long long> dif;
int tc;

void rec(int x, int y) {
//	cerr << x << ' ' << y << endl;
	if (x == r) {
		long long best = -1;
		for (int i = 0; i < c; i++) {
			long long p = 1;
			long long cur = 0;
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cur += p * (clr[j][(k + i) % c] - 1);
					p *= 3ll;
				}
			}

			best = max(best, cur);
		}

		dif.insert(best);

		return;
    }

	for (int i = 1; i <= 3; i++) {
		clr[x][y] = i;
		
		bool flag = true;
		if (!isvalid(x, y))
			flag = false;
		for (int i = 0; i < 4; i++) {
	    //	cerr << flag << endl;
	    	int tx = x + px[i];
	    	int ty = (y + py[i] + c) % c;
	    	if (!onfield(tx, ty))
	    		continue;
			flag = flag && isvalid(tx, ty);
		}

		if (flag) {
			int tx = x;
			int ty = y;
			ty++;
			if (ty == c) {
				tx++;
				ty = 0;
			}
					rec(tx, ty);
		
		}
		
	}

	clr[x][y] = -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < size; i++)
    	for (int j = 0; j < size; j++)
    		clr[i][j] = -1;

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> r >> c;

    	dif.clear();
    	rec(0, 0);

    	printf("Case #%d: %d\n", tnum + 1, (int) dif.size());
    }

    return 0;
}