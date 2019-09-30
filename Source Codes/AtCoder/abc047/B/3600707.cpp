#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int W,H,N;
	cin >> W >> H >> N;
	int xmin = 0, xmax = W, ymin = 0, ymax = H;
	REP(i, N) {
		int a, x,y;
		cin >> x >> y >> a;
		switch(a) {
			case 1:
				xmin = max(xmin, x);
				break;
			case 2:
				xmax = min(xmax, x);
				break;
			case 3:
				ymin = max(ymin, y);
				break;
			case 4:
				ymax = min(ymax, y);
				break;
		}
	}
	cout << max(0,ymax-ymin)*max(0,xmax-xmin) << endl;
	
	return 0;
}