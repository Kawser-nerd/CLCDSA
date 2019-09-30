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

#define TASKNAME "A"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;

void PreCalc(){
}

void solve(){
	int n;
	long long b;   
	scanf(LLD,&b);
	scanf("%d",&n);
	vector<ll> v(37);
	for (int i = 0; i < n; i++){
	    scanf(LLD,&v[i]);
	}
	sort(v.begin(),v.end());
	v.pb(1LL<<60);
	long long total = 0;
	double ans = 0;
	for (int i = 0; i < 37; i++){
		total += v[i];
		for (int j = 0; j <= i; j++){
			long long maxt = min(v[i+1] - 1, (total + b - j) / (i+1));
			long long win = 0;
			long long sum = 0;
			bool ok = true;
			for (int k = 0; k <= i - j; k++)
				win += maxt - v[k];         			
			for (int k = 0; k <= i; k++){
				ok &= (maxt >= v[k]);
				sum += maxt - v[k];
			}
			if (ok)
			ans = max(ans, win * 36.0/(i+1 - j) - (sum + j));
		}
//		eprintf("%d "LLD" "LLD"\n",i, sum, total);
	}
	printf("%.10lf\n",(double)ans);
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