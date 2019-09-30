#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 50
#define lim2 10

int cs,caseno,c,d,s,i,j,n;
string res;
char C[lim][lim2],D[lim][lim2],str[101];

int main()
{
  scanf("%d",&cs);
  for(caseno=1;caseno<=cs;caseno++)
  {
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
      scanf("%s",C[i]);
      if(C[i][0]>C[i][1])
        swap(C[i][0],C[i][1]);
    }
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
      scanf("%s",D[i]);
      if(D[i][0]>D[i][1])
        swap(D[i][0],D[i][1]);
    }
    scanf("%d%s",&n,str);
    res="";
    for(i=1,res+=str[0];i<n;i++)
    {
      for(j=0;j<c;j++)
        if(min(res[res.size()-1],str[i])==C[j][0] && max(res[res.size()-1],str[i])==C[j][1])
          break;
      if(j<c)
        res[res.size()-1]=C[j][2];
      else
      {
        res+=str[i];
        for(j=0;j<d;j++)
          if(res.find(D[j][0])!=-1 && res.find(D[j][1])!=-1)
          {
            res="";
            if(i+1<n)
              res+=str[++i];
            break;
          }
      }
    }
    printf("Case #%d: ",caseno);
    printf("[");
    for(i=0;i<res.size();i++)
    {
      if(i)
        printf(", ");
      printf("%c",res[i]);
    }
    printf("]\n");
  }  
  return 0;
}
