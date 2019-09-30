#include <cstdio>
#include <iostream>
#define DEBUG(X) cout<<__LINE__<<" "<<#X<<": "<<X<<endl;
#define sci(x) int x;scanf("%d",&x);
#define scii(x, y) int x,y;scanf("%d%d",&x,&y);
#define REP(i, y) for(int i=0;i<y;i++)
using namespace std;

const int MAX_N=100001;
const int MAX_M=100001;

int a[MAX_N], b[MAX_M];
int X,Y,N,M;

int main() {
  scanf("%d%d",&N,&M);
  scanf("%d%d",&X,&Y);
  REP(i,N) scanf("%d",&a[i]);
  REP(i,M) scanf("%d",&b[i]);
  bool au; int t,ans,ca,cb;
  for (t=ans=ca=cb=0, au=true; (au&&ca<N)||(!au&&cb<M);){
    if (au) {
      if (t <= a[ca]) {
        t = a[ca] + X;
        au=!au;
      }
      ca++;
    } else {
      if (t <= b[cb]) {
        t = b[cb] + Y;
        ans++;
        au=!au;
      }
      cb++;
    }
  }
  printf("%d\n",ans);
}