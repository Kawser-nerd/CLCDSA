#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 101

int cs,c,s,i,j,x,y,k,a,b,n;
char R[lim];
int A[lim],B[lim];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=a=b=0;i<n;i++)
    {
      cin>>R[i];
      if(R[i]=='O')
        scanf("%d",&A[a++]);
      else
        scanf("%d",&B[b++]);
    }
    s=0;
    for(x=y=1,k=i=j=0;k<n;k++)
    {
      while(1)
      {
        if((R[k]=='O' && x==A[i]) || (R[k]!='O' && y==B[j]))
          break;
        s++;
        if(i<a)
          if(x<A[i])
            x++;
          else if(x>A[i])
            x--;
        if(j<b)
          if(y<B[j])
            y++;
          else if(y>B[j])
            y--;
      }
      s++;
      if(R[k]=='O')
      {
        if(j<b)
          if(y<B[j])
            y++;
          else if(y>B[j])
            y--;
        i++;
      }
      else
      {
        if(i<a)
          if(x<A[i])
            x++;
          else if(x>A[i])
            x--;
        j++;
      }
    }
    printf("Case #%d: %d\n",c,s);
  }  
  return 0;
}
