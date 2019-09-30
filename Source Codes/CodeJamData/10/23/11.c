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
#define MOD 100003
using namespace std;
int N;
int u[]={1,2,3,5,8,14,24,43,77,140,256,472,874,1628,3045,5719,10780,20388,38674,73562,40265,68060,13335,84884};
bool valid(VI v)
{
  int i,num=N;
  while(num!=1)
  {
    for(i=0;i<v.size();++i)if(v[i]==num)break;
    if(i==v.size())return false;
    num=i+1;
  }
  return true;
}
void solve()
{
  int i,mask;
  int ans=0;
  for(mask=0;mask<(1<<(N-1));++mask)
  {
    VI v;
    for(i=0;i<N-1;++i)if(mask&(1<<i))v.pb(i+2);
    if(valid(v))
    {
      //for(i=0;i<v.size();++i)printf("%d ",v[i]);printf("\n");
      ++ans;
      ans%=MOD;
    }
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
    scanf("%d",&N);
    printf("%d\n",u[N-2]);
    //solve();
  }
}