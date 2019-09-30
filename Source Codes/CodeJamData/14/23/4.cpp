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

string code2[60];
bool graph2[60][60];

int N;
string code[60];
bool graph[60][60];
bool used[60];

bool alive[60];
bool visited[60];

void dfs(int x){
	if(visited[x]) return;
	visited[x] = true;
	int i;
	REP(i,N) if(graph[x][i] && alive[i]) dfs(i);
}

bool check(vector <int> order, vector <int> path, int next){
	int i;
	
	REP(i,N) alive[i] = true;
	REP(i,order.size()) alive[order[i]] = false;
	
	bool found = false;
	for(i=path.size()-1;i>=0;i--){
		int x = path[i];
		if(graph[x][next]) found = true;
		if(found) alive[x] = true;
	}
	
	if(!found) return false;
	
	REP(i,N) visited[i] = false;
	REP(i,N) if(alive[i]){
		dfs(i);
		break;
	}
	
	REP(i,N) if(alive[i] && !visited[i]) return false;
	return true;
}

vector <int> func(void){
	int i;
	
	vector <int> order;
	vector <int> path;
	order.push_back(0);
	path.push_back(0);
	
	REP(i,N) used[i] = false;
	used[0] = true;
	
	while(order.size() < N){
		REP(i,N) if(!used[i] && check(order, path, i)){
			order.push_back(i);
			while(1){
				int x = path[path.size()-1];
				if(graph[x][i]) break;
				path.pop_back();
			}
			path.push_back(i);
			used[i] = true;
			break;
		}
		
	//	REP(i,order.size()) cout << order[i] << ' ';
	//	cout << endl;
	//	REP(i,path.size()) cout << path[i] << ' ';
	//	cout << endl;
	}
	
	return order;
}

void main2(void){
	int M,i,j;
	
	cin >> N >> M;
	REP(i,N) cin >> code2[i];
	REP(i,N) REP(j,N) graph2[i][j] = false;
	REP(i,M){
		int a,b;
		cin >> a >> b;
		a--; b--;
		graph2[a][b] = graph2[b][a] = true;
	}
	
	vector <pair <string, int> > v;
	REP(i,N) v.push_back(make_pair(code2[i], i));
	sort(v.begin(),v.end());
	
	REP(i,N) code[i] = v[i].first;
	REP(i,N) REP(j,N) graph[i][j] = graph2[v[i].second][v[j].second];
	
//	REP(i,N) cout << code[i] << endl;
//	REP(i,N) REP(j,N) if(graph[i][j]) cout << i << ' ' << j << endl;
	
	vector <int> ans = func();
	string s;
	REP(i,N) s += code[ans[i]];
	cout << s << endl;
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
