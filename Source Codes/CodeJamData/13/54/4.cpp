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

#define TASKNAME "D"
#define TASKMOD "small"

typedef long long ll;
typedef long double ld;


void PreCalc(){
}

double dp[(1<<20)+100];
char s[25];

void solve(){
	gets(s);
	int n = strlen(s);
	dp[(1<<n)-1] = 0;
	for (int i = (1<<n)-2; i >= 0; i--){
		dp[i] = 0;
		for (int j = 0; j < n; j++){
			int wait = 0;
			int next = j;
			while (i & (1<<next)){
				next++; if (next == n) next = 0;
				wait++;
			}
			dp[i] += n - wait + dp[i | (1<<next)];
		}
		dp[i] /= n;
	}
	int mask = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'X')
			mask |= (1<<i);
	printf("%.10lf\n",dp[mask]);				
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