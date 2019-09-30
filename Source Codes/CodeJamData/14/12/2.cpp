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

#define TASKNAME "B"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;

void PreCalc(){
}

vector< vector<int> > g;

int dfs(int v, int p){
	vector<int> sons;
	for (int i = 0; i < (int)g[v].size(); i++)
		if (g[v][i] != p)
			sons.pb(dfs(g[v][i], v));
	sort(sons.rbegin(), sons.rend());
	if ((int)sons.size() < 2)
		return 1;
	return 1 + sons[0] + sons[1];
}

void solve(){
	int n;
	scanf("%d",&n);
	g = vector< vector<int> > (n);
	for (int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d%d",&a,&b);
		--a,--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, dfs(i, -1));
	printf("%d\n", n - res);
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