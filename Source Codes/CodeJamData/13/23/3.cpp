// I concatenated the dictionary and the input manually.

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

int S;
int trie[1200000][30];
bool goal[1200000];

void init_trie(void){
	int i,j;
	S = 1;
	REP(i,1200000) REP(j,30) trie[i][j] = -1;
}

void update_trie(string s){
	int i;
	
	int cur = 0;
	REP(i,s.length()){
		int c = s[i] - 'a';
		if(trie[cur][c] != -1){
			cur = trie[cur][c];
		} else {
			trie[cur][c] = S;
			S++;
			cur = S-1;
		}
	}
	
	goal[cur] = true;
}

map <pair <int, int>, int> dp[4010];

void pre(void){
	int i;
	string s;
	
	init_trie();
	REP(i,521196){
		cin >> s;
		update_trie(s);
	}
	
	// cout << S << endl;
}

string s;

void main2(void){
	int N,i,j;
	
	cin >> s;
	N = s.length();
	
	dp[0][make_pair(0, 4)] = 0;
	
	REP(i,N){
		snuke(dp[i],itr){
			int st = (itr->first).first;
			int dist = (itr->first).second;
			int val = (itr->second);
			
			REP(j,26){
				int st2,dist2,val2;
				
				if(j == s[i] - 'a'){
					st2 = trie[st][j];
					dist2 = min(dist+1, 4);
					val2 = val;
				} else {
					st2 = trie[st][j];
					if(dist != 4) continue;
					dist2 = 0;
					val2 = val + 1;
				}
				if(st2 == -1) continue;
				
				pair <int, int> p = make_pair(st2, dist2);
				if(dp[i+1].find(p) == dp[i+1].end() || dp[i+1][p] > val2) dp[i+1][p] = val2;
				if(goal[st2]){
					p.first = 0;
					if(dp[i+1].find(p) == dp[i+1].end() || dp[i+1][p] > val2) dp[i+1][p] = val2;
				}
			}
		}
		
		dp[i].clear();
	}
	
	int ans = (1<<29);
	REP(i,5){
		pair <int, int> p = make_pair(0, i);
		if(dp[N].find(p) != dp[N].end()) ans = min(ans, dp[N][p]);
	}
	cout << ans << endl;
	
	dp[N].clear();
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
