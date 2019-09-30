#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int cs,c,i,s,x,n;

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=1,s=0;i<=n;i++)
    {
      scanf("%d",&x);
      s+=(x==i);
    }
    printf("Case #%d: %.6lf\n",c,(double)n-s);
  }  
  return 0;
}
