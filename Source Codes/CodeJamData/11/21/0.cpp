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

#define INF 1.0E+15

int N;
string s[110];
double WP[110],WP2[110][110],OWP[110],OOWP[110],RPI[110];

void main2(void){
	int i,j,k;
	
	cin >> N;
	REP(i,N) cin >> s[i];
	
	REP(i,N) REP(j,N+1){
		double sum = 0.0, cnt = 0.0;
		REP(k,N) if(k != j && s[i][k] != '.'){
			cnt += 1.0;
			if(s[i][k] == '1') sum += 1.0;
		}
		if(j < N) WP2[i][j] = sum / cnt; else WP[i] = sum / cnt;
	}
	
	REP(i,N){
		double sum = 0.0, cnt = 0.0;
		REP(j,N) if(s[i][j] != '.'){
			cnt += 1.0;
			sum += WP2[j][i];
		}
		OWP[i] = sum / cnt;
	}
	
	REP(i,N){
		double sum = 0.0, cnt = 0.0;
		REP(j,N) if(s[i][j] != '.'){
			cnt += 1.0;
			sum += OWP[j];
		}
		OOWP[i] = sum / cnt;
	}
	
	REP(i,N) RPI[i] = 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i];
	
	printf("\n");
	REP(i,N) printf("%.9f\n",RPI[i]);
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
