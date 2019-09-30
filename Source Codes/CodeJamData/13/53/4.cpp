//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;

void PreCalc(){
}

const int MAXN = 11000;
const int MAXM = 21000;

vector<int> g[MAXN];
vector<int> id[MAXN];
//vector<int> L[MAXN];
//vector<int> R[MAXN];
int n;

int from[MAXN];
int to[MAXN];
int Lf[MAXN];
int Rg[MAXN];
int d[MAXN];
bool inpath[MAXN];

void dijkstra(){
	for (int i = 0; i < n; i++)
		d[i] = 1<<30;
	d[0] = 0;
	set<pair<int,int> > s;
	s.insert(mp(0,0));
	while (!s.empty()){
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < (int)g[v].size(); i++){
			int to = g[v][i];
			int dst = (inpath[id[v][i]]?Lf[id[v][i]]:Rg[id[v][i]]);
			if (d[to] > d[v] + dst){
				s.erase(mp(d[to],to));
				d[to] = d[v] + dst;
				s.insert(mp(d[to],to));
			}
		}
	}
}

bool used[MAXN];

bool check(int end){
	memset(used,0,sizeof(used));
	set<pair<int,int> > s;
	s.insert(mp(d[end],end));
	while (!s.empty()){
		int v = s.begin()->second;
//		eprintf("%d\n",v);
		used[v] = true;
		if (v == 1) return true;
		s.erase(s.begin());
		for (int i = 0; i < (int)g[v].size(); i++){
			int to = g[v][i];
			int dst = Lf[id[v][i]];
			if (d[to] >= d[v] + dst && !used[to]){
				s.erase(mp(d[to],to));
				d[to] = d[v] + dst;
				s.insert(mp(d[to],to));
			}
		}
	}
	return false;
}

void solve(){
	int m,p;
	scanf("%d %d %d",&n,&m,&p);
	memset(inpath,0,sizeof(inpath));
	for (int i = 0; i < n; i++)
		g[i].clear(), id[i].clear();
	for (int i = 0; i < m; i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		--a,--b;
		g[a].pb(b);
		id[a].pb(i);
		from[i] = a;
		to[i] = b;
		Lf[i] = c;
		Rg[i] = d;
	}

	vector<int> path(p);

	for (int i = 0; i < p; i++){
		scanf("%d",&path[i]);
		--path[i];
	}
	int sum = 0;

	for (int i = 0; i < p; i++){
		inpath[path[i]] = true;
		sum += Lf[path[i]];
		dijkstra();
		if (d[to[path[i]]] != sum || !check(to[path[i]])){
			printf("%d\n",path[i]+1);
			return;
		}
	}

	printf("Looks Good To Me\n");
}


int main(){
  freopen(TASKNAME"-"TASKMOD".in","r",stdin);
  freopen(TASKNAME"-"TASKMOD".out","w",stdout);
	
  PreCalc();
  TIMESTAMP(PreCalc);	

  char buf[1000];
  int testNum;
  gets(buf);
  sscanf(buf,"%d",&testNum);

  for (int testId = 1; testId <= testNum; testId++){
  	if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
	  	TIMESTAMPf("Test %d",testId);
  	printf("Case #%d: ",testId);
  	solve();                        
  }
      
  TIMESTAMP(end);
  return 0;
}