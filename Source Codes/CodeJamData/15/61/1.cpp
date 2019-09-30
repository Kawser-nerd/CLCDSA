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

#define MAXN 1000010

char buf[MAXN];
string s;
	
int N;
int a[MAXN];
int dpL[190][MAXN],dpR[190][MAXN];

void main2(void){
	int i,j;
	
	scanf("%s", buf);
	s = buf;
	N = s.length();
	REP(i,N) a[i] = s[i] - '0';
	
	REP(i,190) REP(j,N+1) dpL[i][j] = dpR[i][j] = j;
	
	for(int cost=1;cost<190;cost++){
		REP(i,N) if(a[i] <= cost){
			int L = dpL[cost-a[i]][i];
			int R = dpR[cost-a[i]][i+1];
			dpL[cost][R] = min(dpL[cost][R], L);
			dpR[cost][L] = max(dpR[cost][L], R);
		}
		for(i=1;i<=N;i++) dpR[cost][i] = max(dpR[cost][i], dpR[cost][i-1]);
		for(i=N-1;i>=0;i--) dpL[cost][i] = min(dpL[cost][i], dpL[cost][i+1]);
	}
	
	for(i=0;;i++) if(dpR[i][0] == N) break;
	cout << i << endl;
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
