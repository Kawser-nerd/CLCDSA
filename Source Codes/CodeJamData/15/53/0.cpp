#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF 1.0E+18
#define _abs(x) ((x)>0?(x):-(x))

int N,L,R;
double V;
double speed[510],init[510];
vector <int> vl,vr;
double dp[510][510][510]; // captured L, captured R, pos

void main2(void){
	int i,j,k;
	
	cin >> V >> N;
	REP(i,N) cin >> init[i];
	REP(i,N) cin >> speed[i];
	
/*	V = 1000;
	N = 500;
	REP(i,N){
		while(1){
			init[i] = rand() % 20000000 - 10000000;
			if(init[i] != 0) break;
		}
		speed[i] = rand() % 999 + 1;
		speed[i] = i + 1;
	}
	*/
	REP(i,N+10) REP(j,N-1) if(speed[j] < speed[j+1]){
		swap(speed[j], speed[j+1]);
		swap(init[j], init[j+1]);
	}
	
	vl.clear();
	vr.clear();
	REP(i,N) if(init[i] < 0) vl.push_back(i); else vr.push_back(i);
	L = vl.size();
	R = vr.size();
	
	REP(i,L+1) REP(j,R+1) REP(k,N) dp[i][j][k] = INF;
	REP(i,N) dp[0][0][i] = _abs(init[i]) / (V - speed[i]);
	
	REP(i,L+1) REP(j,R+1) REP(k,N) if(dp[i][j][k] < INF / 2.0){
		double t = dp[i][j][k];
		double x = init[k] + t * ((init[k] > 0) ? speed[k] : -speed[k]);
		
		if(i != L){
			int id = vl[i];
			if(init[id] - speed[id] * t < x){
				double t2 = t + (x - (init[id] - speed[id] * t)) / (V - speed[id]);
				dp[i+1][j][id] = min(dp[i+1][j][id], t2);
			} else {
				dp[i+1][j][k] = min(dp[i+1][j][k], t);
			}
		}
		
		if(j != R){
			int id = vr[j];
			if(init[id] + speed[id] * t > x){
				double t2 = t + ((init[id] + speed[id] * t) - x) / (V - speed[id]);
				dp[i][j+1][id] = min(dp[i][j+1][id], t2);
			} else {
				dp[i][j+1][k] = min(dp[i][j+1][k], t);
			}
		}
	}
	
	double ans = INF;
	REP(i,N) ans = min(ans, dp[L][R][i]);
	printf("%.12f\n", ans);
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
