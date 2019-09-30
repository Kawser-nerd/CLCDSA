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
#define TASKMOD "small"

typedef long long ll;
typedef long double ld;


struct point{
	int x,y;
	point(int x,int y):x(x),y(y){}
	point(){}
};

int operator*(const point& a,const point& b){
	return a.x * b.y - a.y * b.x;
}

struct line{
	int a,b,c;
	line(point p1,point p2){
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = -a * p1.x - b *p1.y;
	}
	int side(point p){
		int val = a*p.x + b*p.y + c;
		return (val > 0) - (val < 0);
	}
};

bool checkIn(point a,point b,point c){
	line l(a,b);
	if (l.side(c) != 0) return false;
	if (!(min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x)))
		return false;
	if (!(min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y)))
		return false;
	return true;
}

bool checkIntersection(point a,point b,point c,point d){
	if (checkIn(a,b,c)) return true;
	if (checkIn(a,b,d)) return true;
	if (checkIn(c,d,a)) return true;
	if (checkIn(c,d,b)) return true;
	line l1(a,b);
	line l2(c,d);
	if (l1.side(c) * l1.side(d) != -1) return false;
	if (l2.side(a) * l2.side(b) != -1) return false;
	return true;
}

void PreCalc(){
}

const int MAXN = 15;

point p[MAXN];
bool used[MAXN];
int ord[MAXN];
int best;
int bestord[MAXN];
int n;

void go(int id,int s){
//	for (int i = 0; i < id; i++)
//		eprintf("%d%c",ord[i]," \n"[i==id-1]);
	if (id == n){
		for (int i = 1; i+2 < n; i++)
			if (checkIntersection(p[ord[i]],p[ord[i+1]], p[ord[n-1]],p[ord[0]]))
				return;
		s += p[ord[n-1]] * p[ord[0]];
		if (abs(s) > best){
			best = abs(s);
			memcpy(bestord, ord, sizeof(bestord));
		}
		return;
	}
	for (int i = 0; i < n; i++){
		if (used[i]) continue;
		bool fail = false;

		for (int j = 0; j + 1 < id - 1; j++)
			if (checkIntersection(p[ord[j]],p[ord[j+1]], p[ord[id-1]],p[i]))
				fail = true;
		if (fail) continue;
		used[i] = true;
		ord[id] = i;
		go(id+1, s + p[ord[id-1]] * p[ord[id]]);
		used[i] = false;
	}
}


void solve(){
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d %d",&p[i].x,&p[i].y);
		used[i] = 0;
	}
	used[0] = 1;
	ord[0] = 0;
	best = 0;        
	go(1,0);
	assert(best > 0);
	for (int i = 0; i < n; i++)
		printf("%d%c",bestord[i]," \n"[i==n-1]);
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