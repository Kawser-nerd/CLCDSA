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

string alpha = "PRS";
string dp[15][3];

void pre(void){
	int i,j;
	
	REP(i,3) dp[0][i] += alpha[i];
	
	for(i=1;i<15;i++) REP(j,3){
		string s = dp[i-1][j];
		string t = dp[i-1][(j+1)%3];
		if(s > t) swap(s, t);
		dp[i][j] = s + t;
	}
}

int count(string s, char c){
	int i;
	int ans = 0;
	REP(i,s.length()) if(s[i] == c) ans++;
	return ans;
}

void main2(void){
	int i;
	
	int N,R,P,S;
	cin >> N >> R >> P >> S;
	
	string ans = "IMPOSSIBLE";
	
	REP(i,3){
		string s = dp[N][i];
		if(count(s, 'R') == R && count(s, 'P') == P && count(s, 'S') == S){
			if(ans == "IMPOSSIBLE" || s < ans) ans = s;
		}
	}
	
	cout << ans << endl;
}

int main(void){
	pre();
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
