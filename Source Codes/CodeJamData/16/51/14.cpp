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
string s;
int dp[2][2][20010];

void main2(void){
	int pos,i,j,k;
	
	cin >> s;
	N = s.length();
	
	REP(i,2) REP(j,2) REP(k,N+1) dp[i][j][k] = -1;
	dp[0][0][0] = dp[0][1][0] = 0;
	
	REP(pos,N){
		int cur = pos%2, next = (pos+1)%2;
		REP(i,2) REP(j,N+1) dp[next][i][j] = -1;
		
		REP(i,2) REP(j,N+1) if(dp[cur][i][j] != -1){
			int top = (i + j) % 2;
			int x = ((s[pos] == 'C') ? 0 : 1);
			
			// add
			if(j == 0){
				dp[next][x][j+1] = max(dp[next][x][j+1], dp[cur][i][j]);
			} else if(x == top){
				dp[next][i][j+1] = max(dp[next][i][j+1], dp[cur][i][j]);
			}
			
			// pop
			if(j > 0){
				int cost = dp[cur][i][j];
				if(x != top) cost++;
				dp[next][i][j-1] = max(dp[next][i][j-1], cost);
			}
		}
		
		int tmp = max(dp[next][0][0], dp[next][1][0]);
		dp[next][0][0] = dp[next][1][0] = tmp;
	}
	
	int ans = dp[0][0][0];
	cout << 5 * (N / 2) + 5 * ans << endl;
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
