#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int N,M; set<int> X[3000]; int malt[3000]; int Y[3000];

char bitcount(unsigned long l)
{ register char i=0;while(l){l&=(l-1);i++;}return(i); }

int likes(int c,int i) { if (Y[i]) return (malt[c]==(i+1)); else
return (X[c].count(i+1) > 0); }

int happy(int c) { for(int i=0;i<N;i++) { if(likes(c,i)) return true; } return false; }

int sat() { for(int i=0;i<M;i++) { if (!happy(i)) return i; } return -1; }

int doit() { int c=sat(); if (c==-1) return true; else
  { if (malt[c]>0) {Y[malt[c]-1]=1; return doit();} else return false;}  }

int main()
{
int C;

scanf("%d",&C);

for(int loop=1;loop<=C;loop++)
{
  scanf("%d",&N);
  scanf("%d",&M);

  for(int i=0;i<M;i++)
  {
    int T;
    X[i].clear(); malt[i] = 0;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      if(y) malt[i]=x; else { X[i].insert(x); }
    }
  }

  for(int i=0;i<N;i++) Y[i]=0;

  if (!doit()) { printf("Case #%d: IMPOSSIBLE\n",loop); }
   else
 { printf("Case #%d:",loop); for(int i=0;i<N;i++) printf(" %d",Y[i]); putchar(10); }
}

}
