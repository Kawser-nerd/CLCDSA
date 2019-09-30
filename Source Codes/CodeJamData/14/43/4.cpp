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

const int MAXN = 1010;


struct Rect {
	int x0, x1, y0, y1;
};

Rect rs[MAXN];
vector<int> g[MAXN];

int dist(int l1, int r1, int l2, int r2){
	if (l1 > l2) {
		swap(l1, l2);
		swap(r1, r2);
	}
	return max(l2 - r1 - 1, 0);
}


int dist(Rect a, Rect b){
	int dx = dist(a.x0, a.x1, b.x0, b.x1);
	int dy = dist(a.y0, a.y1, b.y0, b.y1);
//	eprintf("Dist %d..%dx%d..%d and %d..%dx%d..%d = %d\n", a.x0, a.x1, a.y0, a.y1, b.x0, b.x1, b.y0, b.y1, max(dx, dy));
	return max(dx, dy);
}

void solve(){
	int w, h, b;
	scanf("%d %d %d",&w,&h,&b);
	
	int n = b + 2;
	for (int i = 0; i < n; i++)
		g[i].clear();

	rs[0].x0 = -1, rs[0].x1 = -1, rs[0].y0 = 0, rs[0].y1 = h;
	rs[n-1].x0 = w, rs[n-1].x1 = w, rs[n-1].y0 = 0, rs[n-1].y1 = h;

	for (int i = 1; i <= b; i++)
		scanf("%d %d %d %d",&rs[i].x0,&rs[i].y0,&rs[i].x1,&rs[i].y1);

	vector<int> dst(n, 1<<30);
	vector<bool> used(n, 0);
	dst[0] = 0;
	for (int i = 0; i < n; i++){
		int best = -1;
		for (int j = 0; j < n; j++)
			if (!used[j])
				if (best == -1 || dst[best] > dst[j])
					best = j;
		used[best] = true;

		for (int j = 0; j < n; j++)
			dst[j] = min(dst[j], dst[best] + dist(rs[best], rs[j]));
	}
	printf("%d\n", dst[n-1]);
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