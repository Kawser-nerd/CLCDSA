#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list>
#include <cassert>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v)) 
typedef long long ll; 

typedef struct Side { vector<int> triangles; } Side;
typedef struct Triangle { vector<int> sides; } Triangle;
typedef struct Point { vector<int> sides; } Point;

int n;
vector<Side> sides;
vector<Triangle> triangles;
vector<Point> points;

vector<vector<int> > mem;
int go(int t,int i) {
	int &ret=mem[t][i];
	if(ret==-1) {
		ret=0;
		int s=triangles[t].sides[i];
		REPSZ(i,sides[s].triangles) {
			int tt=sides[s].triangles[i];
			if(t==tt) continue;
			int cur=1;
			REPSZ(j,triangles[tt].sides) {
				int ss=triangles[tt].sides[j];
				if(s==ss) continue;
				cur+=go(tt,j);
			}
			if(cur>ret) ret=cur;
		}
	}
	return ret;
}

void run(int casenr) {
	sides.clear();
	triangles.clear();
	points.clear();
	{ Triangle t; REP(i,3) t.sides.PB(i); triangles.PB(t); }
	REP(i,3) { Side s; s.triangles.PB(0); sides.PB(s); }
	REP(i,3) { Point p; p.sides.PB(i); p.sides.PB((i+2)%3); points.PB(p); }
	
	scanf("%d",&n);
	REP(i,n-3) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		set<int> have; REPSZ(j,points[a].sides) have.insert(points[a].sides[j]);
		int abi=-1; REPSZ(j,points[b].sides) if(have.count(points[b].sides[j])) { abi=points[b].sides[j]; break; } assert(abi!=-1);
		int aci=SZ(sides),bci=SZ(sides)+1,ti=SZ(triangles);
		Side ac; ac.triangles.PB(ti); sides.PB(ac);
		Side bc; bc.triangles.PB(ti); sides.PB(bc);
		sides[abi].triangles.PB(ti);
		Triangle t; t.sides.PB(abi); t.sides.PB(bci); t.sides.PB(aci); triangles.PB(t);
		Point p; p.sides.PB(aci); p.sides.PB(bci); points.PB(p);
		points[a].sides.PB(aci); points[b].sides.PB(bci);
	}
	
//	REPSZ(i,sides) { printf("side %d:",i); REPSZ(j,sides[i].triangles) printf(" %d",sides[i].triangles[j]); puts(""); }
//	REPSZ(i,triangles) { printf("triangle %d:",i); REPSZ(j,triangles[i].sides) printf(" %d",triangles[i].sides[j]); puts(""); }
//	REPSZ(i,points) { printf("point %d:",i); REPSZ(j,points[i].sides) printf(" %d",points[i].sides[j]); puts(""); }

	mem=vector<vector<int> >(SZ(triangles),vector<int>(3,-1));
	int ret=0;
	REPSZ(i,triangles) REP(j,3) {
		int cur=3+go(i,j);
		if(cur>ret) ret=cur;
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
