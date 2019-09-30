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

#define INF (1<<29)

int V,E;
bool edge[410][410];
int cost[410][410][410];
int dist[410][410],dp[410][410];

vector <int> cities[410];

void main2(void){
	int d,i,j,k,p;
	
	cin >> V >> E;
	REP(i,V) REP(j,V) edge[i][j] = false;
	REP(i,V) REP(j,V) REP(k,V) cost[i][j][k] = 0;
	REP(i,V) REP(j,V) dist[i][j] = INF;
	REP(i,V) REP(j,V) dp[i][j] = -INF;
	
	REP(i,E){
		string s;
		cin >> s;
		REP(j,s.length()) if(s[j] == ',') break;
		int a = atoi(s.substr(0,j).c_str()), b = atoi(s.substr(j+1).c_str());
		edge[a][b] = edge[b][a] = true;
	}
	REP(i,V) edge[i][i] = true;
	
	REP(i,V) REP(j,V) if(i == j) dist[i][j] = 0; else if(edge[i][j]) dist[i][j] = 1;
	REP(k,V) REP(i,V) REP(j,V) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	
	REP(i,V) REP(j,V) if(edge[i][j]) REP(k,V) if(edge[j][k]) REP(p,V) if(edge[k][p] && !edge[i][p] && !edge[j][p]) cost[i][j][k]++;
	
	int D = dist[0][1];
	
	int init = 0;
	REP(i,V) if(edge[0][i]) init++;
	
	if(D == 1){
		cout << 0 << ' ' << init - 1 << endl;
		return;
	}
	
	REP(i,D+1) cities[i].clear();
	REP(i,V) if(dist[0][i] + dist[1][i] == D) cities[dist[0][i]].push_back(i);
	
	REP(i,cities[1].size()){
		int x = cities[1][i];
		if(edge[0][x]) dp[0][x] = max(dp[0][x],init+cost[0][0][x]);
	}
	
	REP(d,D-2){
		REP(i,cities[d].size()){
			int x = cities[d][i];
			REP(j,cities[d+1].size()){
				int y = cities[d+1][j];
				if(!edge[x][y]) continue;
				REP(k,cities[d+2].size()){
					int z = cities[d+2][k];
					if(edge[y][z]) dp[y][z] = max(dp[y][z],dp[x][y]+cost[x][y][z]);
				}
			}
		}
	}
	
	int sum = -INF;
	REP(i,cities[D-2].size()){
		int x = cities[D-2][i];
		REP(j,cities[D-1].size()){
			int y = cities[D-1][j];
			if(!edge[x][y]) continue;
			sum = max(sum,dp[x][y]);
		}
	}
	
	cout << D - 1 << ' ' << sum - D << endl;
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
