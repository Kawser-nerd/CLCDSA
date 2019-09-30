#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

ll x[510][510],y[510][510],z[510][510],xs[510][510],ys[510][510],zs[510][510];

void main2(void){
	int X,Y,D,i,j;
	
	cin >> X >> Y >> D;
	REP(i,X+1) REP(j,Y+1) x[i][j] = y[i][j] = z[i][j] = xs[i][j] = ys[i][j] = zs[i][j] = 0;
	
	REP(i,X){
		string s;
		cin >> s;
		REP(j,Y){
			z[i][j] = s[j] - '0';
			x[i][j] = z[i][j] * i;
			y[i][j] = z[i][j] * j;
		}
	}
	
	REP(i,X) REP(j,Y){
		xs[i+1][j+1] = xs[i+1][j] + xs[i][j+1] - xs[i][j] + x[i][j];
		ys[i+1][j+1] = ys[i+1][j] + ys[i][j+1] - ys[i][j] + y[i][j];
		zs[i+1][j+1] = zs[i+1][j] + zs[i][j+1] - zs[i][j] + z[i][j];
	}
	
	for(D=min(X,Y);D>=3;D--){
		REP(i,X-D+1) REP(j,Y-D+1){
			ll xsum = xs[i][j] + xs[i+D][j+D] - xs[i][j+D] - xs[i+D][j] - x[i][j] - x[i+D-1][j+D-1] - x[i][j+D-1] - x[i+D-1][j];
			ll ysum = ys[i][j] + ys[i+D][j+D] - ys[i][j+D] - ys[i+D][j] - y[i][j] - y[i+D-1][j+D-1] - y[i][j+D-1] - y[i+D-1][j];
			ll zsum = zs[i][j] + zs[i+D][j+D] - zs[i][j+D] - zs[i+D][j] - z[i][j] - z[i+D-1][j+D-1] - z[i][j+D-1] - z[i+D-1][j];
			if(zsum * (i + (i+D-1)) != xsum * 2) continue;
			if(zsum * (j + (j+D-1)) != ysum * 2) continue;
			cout << D << endl;
			return;
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
