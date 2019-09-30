#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

int m,n;
char a[512][512]; 
int b[512][512];

void cap(int i, int j, int k) { if((i>=0)&&(j>=0)&&(b[i][j]>k)) b[i][j]=k; }


void _case(int casenum)
{
  scanf("%d %d ",&m,&n);

  REP(i,m)REP(j,n/4)
  {
    char ch; scanf("%c ",&ch); if(ch>='A') ch=ch-'A'+10; else ch=ch-'0';
    a[i][4*j]=(ch>>3)&1;
    a[i][4*j+1]=(ch>>2)&1;
    a[i][4*j+2]=(ch>>1)&1;
    a[i][4*j+3]=(ch)&1;
  }

//REP(i,m){REP(j,n)printf("%c",a[i][j]?'#':'.');printf("\n");}printf("\n");

  REP(i,m)REP(j,n) b[i][j]=1;
  FOR(k,2,min(m,n))
    FOR(i,0,m-k)FOR(j,0,n-k)
      if((a[i][j]!=a[i][j+1])&&(a[i][j]!=a[i+1][j])&&(a[i][j]==a[i+1][j+1]))
        if((b[i][j]==(k-1))&&(b[i][j+1]==(k-1))&&(b[i+1][j]==(k-1))&&(b[i+1][j+1]==(k-1))) b[i][j]=k;

//REP(i,m){REP(j,n)printf("%d.",b[i][j]);printf("\n");}printf("\n");

  vector<pair<int,int> > res;

  FORD(k,min(m,n),1)
  {
    int poc=0;
    FOR(i,0,m-k)FOR(j,0,n-k)
      if(b[i][j]==k)
      {
        poc++;
        REP(ii,k)REP(jj,k) b[i+ii][j+jj]=0;
        FOR(kk,1,k-1)
        {
          FOR(ii,-kk,k-1) cap(i+ii,j-kk,kk);
          FOR(jj,-kk,k-1) cap(i-kk,j+jj,kk);
        }
      }
    if(poc) res.PB(MP(k,poc));
//REP(i,m){REP(j,n)printf("%d.",b[i][j]);printf("\n");}printf("\n");
  }

  printf("Case #%d: %d\n",casenum,res.size());
  REP(i,(int)(res.size())) printf("%d %d\n",res[i].first,res[i].second);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
