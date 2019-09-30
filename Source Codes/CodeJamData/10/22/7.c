#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<ctime>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define VI vector<int>
#define PQ priority_queue
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
using namespace std;
int P[64],V[64],N,K,B,T;
void read()
{
  int i;
  scanf("%d %d %d %d",&N,&K,&B,&T);
  for(i=0;i<N;++i)scanf("%d",&P[i]);
  for(i=0;i<N;++i)scanf("%d",&V[i]);
}
void slow()
{
  if(K==0)
  {
    printf("0\n");
    return;
  }
  int i,j,l,ans=0;
  int passed=0;
  bool used[64];
  for(i=0;i<N;++i)used[i]=false;
  for(i=N-1;i>=0;--i)
  {
    int g=P[i]+V[i]*T;
    if(g>=B)
    {
      ++passed;
      used[i]=true;
      if(passed==K)break;
    }
  }
  if(passed<K)
  {
    printf("IMPOSSIBLE\n");
    return;
  }
  for(j=i;j<N;++j)
  {
    if(!used[j])continue;
    for(l=j+1;l<N;++l)if(!used[l])++ans;
  }
  printf("%d\n",ans);
}
int main()
{
  int tc,T;
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc)
  {
    printf("Case #%d: ",tc);
    read();
    slow();
  }
  return 0;
}