#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int cs,c,n,i,s;
int A[1001];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=s=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      s=s^A[i];
    }
    printf("Case #%d: ",c);
    if(s)
      printf("NO\n");
    else
    {
      sort(A,A+n);
      for(i=1,s=0;i<n;i++)
        s+=A[i];
      printf("%d\n",s);
    }
  }  
  return 0;
}
