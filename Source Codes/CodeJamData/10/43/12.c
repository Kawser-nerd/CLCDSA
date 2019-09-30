#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<cstdlib>
#include<list>
#include<set>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;
bool A[128][128];
int N,R;
void read()
{
  int i,j,x1,y1,x2,y2;
  N=0;
  for(i=0;i<128;++i)
    for(j=0;j<128;++j)A[i][j]=false;
  cin>>R;
  for(i=0;i<R;++i)
  {
    cin>>x1>>y1>>x2>>y2;
    --x1;--x2;--y1;--y2;
    for(j=x1;j<=x2;++j)
      for(int k=y1;k<=y2;++k)A[j][k]=true;
    N=max(N,max(x2,y2)+1);
  }
}
bool check()
{
  int i,j;
  for(i=0;i<N;++i)
    for(j=0;j<N;++j)if(A[i][j])return false;
  return true;
}
void solve()
{
  int time,i,j;
  bool B[128][128];
  for(time=0;;++time)
  {
    if(check())break;
    for(i=0;i<N;++i)
      for(j=0;j<N;++j)
      {
        B[i][j]=A[i][j];
        if(i==0||(!A[i-1][j]))
        {
          if(j==0||(!A[i][j-1]))B[i][j]=false;
        }
        if(i!=0&&A[i-1][j])
        {
          if(j!=0&&A[i][j-1])B[i][j]=true;
        }
      }
    for(i=0;i<N;++i)
      for(j=0;j<N;++j)A[i][j]=B[i][j];
  }
  printf("%d\n",time);
}
int main()
{
  int tc,T;
  cin>>T;
  for(tc=1;tc<=T;++tc)
  {
    printf("Case #%d: ",tc);
    read();
    solve();
  }
  return 0;
}