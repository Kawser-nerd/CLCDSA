#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N=100;
int _,h,w;
char b[N][N];

int main() {
   scanf("%d",&_);
   REP(test,_) {
      scanf("%d%d ",&h,&w);
      REP(i,h) gets(b[i]);
      int ok=1;
      REP(i,h) REP(j,w) if (b[i][j]=='#') {
	 if (b[i+1][j]=='#' && b[i][j+1]=='#' && b[i+1][j+1]=='#')
	    b[i][j]=b[i+1][j+1]='/', b[i+1][j]=b[i][j+1]='\\';
	 else ok=0;
      }
      printf("Case #%d:\n",test+1);
      if (!ok) puts("Impossible");
      else REP(i,h) puts(b[i]);
   }
}
