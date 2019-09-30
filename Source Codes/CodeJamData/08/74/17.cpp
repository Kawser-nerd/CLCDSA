#include <map>     
#include <set>     
#include <cmath>    
#include <cstdio>   
#include <vector>     
#include <string>     
#include <sstream>    
#include <iostream>    
#include <algorithm>     
using namespace std;     
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)     
#define FORE(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)     
#define SET(x, v) memset(x, v, sizeof (x))     
#define sz size()     
#define cs c_str()     
#define pb push_back     
#define mp make_pair
#define bpc __builtin_popcount
#define mask(X,Y) (1<<(c*X+Y)) 
typedef long long ll;
char cach[1<<16][5][5];
char dat[16][16];
int r, c;
// mask(x,y)
// (1<<(c*x + y))
int doit(int stat, int x, int y) {
	char& ret = cach[stat][x][y];
	if(ret!=-1) return ret;
	// 0: Alice
	// 1: Bob
	ret = 1;
	FOR(i,-1,2)
		FOR(j,-1,2) {
			int px = x + i;
			int py = y + j;
			if(px>=0 && py>=0 && px<r && py<c && dat[px][py]=='.') {
				int v =mask(px,py);
				if(stat&v)continue;
				stat^=v;
				int p = doit(stat, px, py);
				if (p==1) {
					return ret = 0;
				}
				stat^=v;
			}
		}
	return ret;
}
int main() {
	int e= 0, T;
	freopen("D.in","r",stdin);
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d ",&r,&c);
		FOR(i,0,r) 
			scanf("%s",dat[i]);
		int x, y;
		FOR(i,0,r)
			FOR(j,0,c)
				if(dat[i][j]=='K') {
					x=i, y=j;
					break;
				}
		SET(cach, -1);
		int v = doit(mask(x,y), x, y);
		printf("Case #%d: %c\n",++e,'A'+v);
	}
	return 0;
}

