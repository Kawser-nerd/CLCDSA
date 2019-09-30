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

int N;
bool graph[60][60];
bool used[60];

#define INF (1<<29)

int K;
int l[20],r[20],L,R;
int dp[(1<<16)][30][30];

int func(void){
	int mask,i,j,k;
	
//	cout << K << ' ' << L << ' ' << R << endl;
//	REP(i,K) cout << l[i] << ' ' << r[i] << endl;
//	cout << endl;
	
	REP(mask,(1<<K)) REP(i,L+1) REP(j,R+1) dp[mask][i][j] = INF;
	dp[0][0][0] = 0;
	
	REP(mask,(1<<K)) REP(i,L+1) REP(j,R+1){
		if(i > 0 && j > 0) dp[mask][i][j] = min(dp[mask][i][j], dp[mask][i-1][j-1] + 1);
		
		int mask2 = mask;
		
		while(mask2 > 0){
			int lsum = 0, rsum = 0;
			REP(k,K) if(mask2&(1<<k)){
				lsum += l[k];
				rsum += r[k];
			}
			
			int cost = max(lsum, rsum);
			cost = cost * cost;
			
			int i2 = i, j2 = j;
			if(lsum > rsum) j2 -= (lsum - rsum);
			if(rsum > lsum) i2 -= (rsum - lsum);
			
			if(i2 >= 0 && j2 >= 0) dp[mask][i][j] = min(dp[mask][i][j], dp[mask^mask2][i2][j2] + cost);
			mask2 = ((mask2 - 1) & mask);
		}
	}
	
	return dp[(1<<K)-1][L][R];
}

void main2(void){
	int i,j,k;
	
	cin >> N;
	int cnt = 0;
	
	REP(i,2*N) REP(j,2*N) graph[i][j] = (i == j);
	REP(i,N){
		string s;
		cin >> s;
		REP(j,N) if(s[j] == '1'){
			graph[i][N+j] = graph[N+j][i] = true;
			cnt++;
		}
	}
	REP(k,2*N) REP(i,2*N) REP(j,2*N) if(graph[i][k] && graph[k][j]) graph[i][j] = true;
	
	K = L = R = 0;
	
	REP(i,2*N) used[i] = false;
	
	int ans = 0;
	
	REP(i,2*N) if(!used[i]){
		int a = 0, b = 0;
		REP(j,2*N) if(graph[i][j]){
			if(j < N) a++; else b++;
			used[j] = true;
		}
		
		if(a == 1 && b == 0){
			L++;
		} else if(a == 0 && b == 1){
			R++;
		} else if(a == b){
			ans += a * b;
		} else {
			l[K] = a;
			r[K] = b;
			K++;
		}
	}
	
	ans += func() - cnt;
	cout << ans << endl;
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
