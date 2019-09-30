#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;
typedef long double LD;

struct xy {
	int x,y;
	xy(int _x=0, int _y=0): x(_x), y(_y) { }
	int d2() { return x*x+y*y; }
};

xy operator-(const xy&p, const xy&q) { return xy(p.x-q.x, p.y-q.y); }
bool operator==(const xy&p, const xy&q) { return p.x==q.x && p.y==q.y; }

xy tabA[3];
xy tabB[3];
int perm[3];

void testcase(int tNum) {
	printf("Case #%d: ",tNum);
	
	FOR(i,0,3) scanf("%d %d",&tabA[i].x,&tabA[i].y);
	FOR(i,0,3) scanf("%d %d",&tabB[i].x,&tabB[i].y);
	
	FOR(i,0,3) perm[i] = i;
	do {
	
		if(tabA[0]==tabB[perm[0]] && tabA[1]==tabB[perm[1]] && tabA[2]==tabB[perm[2]]) {
			printf("%d %d\n",tabA[0].x,tabA[0].y);
			return;
		}
	
		xy v = tabA[1]-tabA[0], u=tabA[2]-tabA[0], w=tabA[2]-tabA[1];
		xy v2 = tabB[perm[1]]-tabB[perm[0]], u2=tabB[perm[2]]-tabB[perm[0]], w2=tabB[perm[2]]-tabB[perm[1]];
		xy P = tabB[perm[0]]-tabA[0];
		
		if(v.d2()*1LL*u2.d2()!=v2.d2()*1LL*u.d2()) continue;
		if(w.d2()*1LL*u2.d2()!=w2.d2()*1LL*u.d2()) continue;
		
		LL Ax = v.x-v2.x;
		LL Bx = u.x-u2.x;
		LL Ay = v.y-v2.y;
		LL By = u.y-u2.y;
		LL Cx = P.x;
		LL Cy = P.y;
		
		LL M = Ax*By-Ay*Bx;
		LL Mb = Ax*Cy-Cx*Ay;
		LL Ma = Bx*Cy - By*Cx;
				
		if(Ax*By==Ay*Bx) continue;
		
		LD b = Mb*1.0/M;
		LD a = -Ma*1.0/M;
		
		LD x = tabA[0].x + P.x + v2.x*a + u2.x*b;
		LD y = tabA[0].y + P.y + v2.y*a + u2.y*b;
		
		printf("%.6llf %.6llf\n",x,y);
		return;
	
	} while(next_permutation(perm, perm+3));
	
	printf("No Solution\n");
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
