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

int L,U;
double lx[110],ly[110],ux[110],uy[110];

double func(double x){
	int i;
	double ans = 0.0;
	
	// up
	REP(i,U-1){
		if(x > ux[i+1]){
			ans += (uy[i] + uy[i+1]) / 2.0 * (ux[i+1] - ux[i]);
		} else if(x > ux[i]){
			double tmp = uy[i] + (uy[i+1] - uy[i]) / (ux[i+1] - ux[i]) * (x - ux[i]);
			ans += (uy[i] + tmp) / 2.0 * (x - ux[i]);
		}
	//	cout << ans << endl;
	}
	
	// low
	REP(i,L-1){
		if(x > lx[i+1]){
			ans -= (ly[i] + ly[i+1]) / 2.0 * (lx[i+1] - lx[i]);
		} else if(x > lx[i]){
			double tmp = ly[i] + (ly[i+1] - ly[i]) / (lx[i+1] - lx[i]) * (x - lx[i]);
			ans -= (ly[i] + tmp) / 2.0 * (x - lx[i]);
		}
	//	cout << ans << endl;
	}
	
	return ans;
}

void main2(void){
	int W,G,i,iter;
	
	cin >> W >> L >> U >> G;
	REP(i,L) cin >> lx[i] >> ly[i];
	REP(i,U) cin >> ux[i] >> uy[i];
	
	double total = func(W);
//	cout << total << endl;
	
	REP(i,G-1){
		double s = total / G * (i + 1);
		double low = 0.0, high = W, mid;
		REP(iter,100){
			mid = (high + low) / 2.0;
			if(func(mid) > s) high = mid; else low = mid;
		}
		printf("%.9f\n",mid);
	}
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d:\n",t+1);
		main2();
	}
	return 0;
}
