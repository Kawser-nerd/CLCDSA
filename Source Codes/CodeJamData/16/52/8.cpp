#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;

R __ran(){
	int t = rand();
	return ((R)t) / 32768;
}

R ran(){
	return (R)(rand()+__ran()) / ((int)RAND_MAX+1);
}

string merge(string a, string b){
	int n = a.size();
	int m = b.size();
	string ret;
	int i, j;
	i = j = 0;
	while(n+m > 0){
		if(ran() >= (R)n/(n+m)){
			ret.pb(b[j++]);
			m--;
		}
		else{
			ret.pb(a[i++]);
			n--;
		}
	}
	return ret;
}

vector<int> sons[MAXN];
int p[MAXN];
char t[5][MAXN];
char s[MAXN];
int cnt[5];

string get(int i){
	string x;
	for(int j = 0; j < sons[i].size(); j++)
		x = merge(x, get(sons[i][j]));
	x.pb(' ');
	for(int j = x.size()-1; j > 0; j--)
		x[j] = x[j-1];
	x[0] = s[i-1];
	return x;
}

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
//	for(int i = 0; i < 1000; i++){
//		printf("%.10f\n", __ran());
//	}
	//cout<<merge(string("ABC"), string("QWE"))<<endl;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int n, m;
		int i, j, k;
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &p[i]);
			if(p[i] != 0)
				sons[p[i]].pb(i);
		}
		scanf("%s", s);
		scanf("%d", &m);
		for(i = 0; i < m; i++)
			scanf("%s", t[i]);
		memset(cnt, 0, sizeof cnt);
		int M = 1e4/2;
		for(i = 0; i < M; i++){
			string x;
			for(j = 1; j <= n; j++)
				if(p[j] == 0)
					x = merge(x, get(j));
			//cout<<x<<endl;
			for(j = 0; j < m; j++)
				if(strstr(x.c_str(), t[j]))
					cnt[j]++;
		}
		printf("Case #%d:", i0);
		for(i = 0; i < m; i++)
			printf(" %.10f", (R)cnt[i]/M);
		puts("");
		fflush(stdout);
		for(i = 1; i <= n; i++)
			sons[i].clear();
	}
	return 0;
}
