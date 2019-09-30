#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int a,b,ans;
  scanf("%d %d",&a,&b);
  ans=max(a+b,a-b);
  ans=max(ans,a*b);
  printf("%d\n",ans);
}