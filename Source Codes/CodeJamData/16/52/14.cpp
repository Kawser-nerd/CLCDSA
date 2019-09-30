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

double F[110];
string head;

int N;
int parent[110];
bool used[110];

int sz[110];
vector <int> child[110];
double dp[110];
bool root[110];
double freq[110];

double comb(int n, int k){
	return F[n] / F[k] / F[n-k];
}

int get_random_id(void){
	int i,j;
	
	REP(i,N) freq[i] = 0;
	double total = 0.0;
	
	REP(i,N) if(!used[i] && root[i]){
	/*	int sum = 0;
		double prod = 1.0;
		
		REP(j,N) if(!used[j]) if((j != i && root[j]) || parent[j] == i){
			sum += sz[j];
			prod *= dp[j] * comb(sum, sz[j]);
		}
		
		freq[i] = prod;
		total += prod; */
		
		freq[i] = sz[i];
		total += sz[i];
	}
	
	double r = (rand() % 10000 * 10000 + rand() % 10000) / (1.0E+8);
	double sum = 0.0;
	int first = -1;
	
	REP(i,N) if(root[i]){
		first = i;
		sum += freq[i] / total;
		if(sum > r) return i;
	}
	
	return first;
}

void dfs(int x){
	int i;
	
	double prod = 1.0;
	int cnt = 0;
	
	REP(i,child[x].size()){
		int y = child[x][i];
		dfs(y);
		cnt += sz[y];
		prod *= dp[y] * comb(cnt, sz[y]);
	}
	
	sz[x] = cnt + 1;
	dp[x] = prod;
}

void pre(void){
	int i;
	
	REP(i,N) child[i].clear();
	REP(i,N) if(parent[i] != -1) child[parent[i]].push_back(i);
	
	REP(i,N) if(parent[i] == -1) dfs(i);
}

string random_sampling(void){
	int i,j;
	
	REP(i,N) used[i] = false;
	REP(i,N) root[i] = (parent[i] == -1);
	
	string ans;
	REP(i,N){
		int id = get_random_id();
		ans += head[id];
		used[id] = true;
		REP(j,child[id].size()) root[child[id][j]] = true;
	}
	
	return ans;
}

int Q;
string query[110];
double cnt[110];

bool check(string &s, string &t){
	int N = s.length();
	int M = t.length();
	
	if(N < M) return false;
	
	int i,j;
	REP(i,N-M+1){
		REP(j,M) if(s[i+j] != t[j]) break;
		if(j == M) return true;
	}
	
	return false;
}

void main2(void){
	int i,j;
	
	srand(452852);
	
	F[0] = 1.0;
	for(i=1;i<110;i++) F[i] = F[i-1] * i;
	
	cin >> N;
	REP(i,N) cin >> parent[i];
	REP(i,N) parent[i]--;
	pre();
	
	// REP(i,N) cout << i << ' ' << sz[i] << ' ' << dp[i] << endl;
	
	cin >> head;
	
	cin >> Q;
	REP(i,Q) cin >> query[i];
	
	REP(i,Q) cnt[i] = 0.0;
	REP(i,10000){
		string t = random_sampling();
	//	cout << t << endl;
		REP(j,Q) if(check(t, query[j])) cnt[j]++;
	}
	
	REP(i,Q) printf(" %.4f", cnt[i] / 10000.0);
	cout << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d:", tc+1);
		main2();
	}
	return 0;
}
