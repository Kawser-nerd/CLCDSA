//MADE BY lordmonsoon A.I.
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<iostream>
#include<utility>
#include<bitset>

using namespace std;

#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define fst first
#define snd second
#define pb push_back
#define SIZE(a) (int)(a.size())
#define LENGTH(a) (int)(a.length())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define FORD(i,n,m) for(int i=(n);i>=(m);i--)
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define ABS(a) ( (a)<0 ? -(a) : (a))
#define STRUMIEN(A,B) istringstream A(B)
#define SORT(A) sort(A.begin(),A.end())


////////////////////////////////////////////////////////////////////////////////
int t,n,x,y,m;
int a,b,c,d;

long long W[3][3];

int main()
{
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            long long ans = 0;
            scanf("%d",&n);
            scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&x,&y,&m);
            
            REP(i,3) REP(j,3) W[i][j] = 0;
            W[x%3][y%3]++;
            FOR(i,1,n-1)
            {
                  x = (a*(long long)(x) + b)%m;
                  y = (c*(long long)(y) + d)%m;
                  W[x%3][y%3]++;
            }
            
            REP(ax,3) REP(ay,3)
            {
                  long long d1 = W[ax][ay];
                  W[ax][ay]--;
                  REP(bx,3) REP(by,3)
                  {
                        long long d2 = W[bx][by];
                        W[bx][by]--;
                        REP(cx,3) REP(cy,3)
                              if( (ax+bx+cx)%3==0 && (ay+by+cy)%3==0)
                              {
                                    ans+= (d1*d2)*W[cx][cy];
                              }
                        W[bx][by]++;
                  }
                  W[ax][ay]++;
            }
            
            printf("Case #%d: %I64d\n",t2,ans/6);
      }
      return 0;
}
