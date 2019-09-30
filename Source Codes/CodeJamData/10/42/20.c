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
int M[1028],P,C[12][550];
void read()
{
  int i,j;
  cin>>P;
  for(i=0;i<(1<<P);++i)cin>>M[i];
  for(i=P;i>=1;--i)
    for(j=0;j<(1<<(i-1));++j)cin>>C[i][j];
}
void solve()
{
  int rnd,i,j,ans=0;
  int F[550];
  for(rnd=P;rnd>=1;--rnd)
  {
    for(i=0;i<(1<<rnd);i+=2)
    {
      if(M[i]==0||M[i+1]==0)
      {
        ++ans;
        F[i/2]=0;
      }
      else F[i/2]=min(M[i]-1,M[i+1]-1);
    }
    for(i=0;i<(1<<(rnd-1));++i)M[i]=F[i];
  }
  printf("%d\n",ans);
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