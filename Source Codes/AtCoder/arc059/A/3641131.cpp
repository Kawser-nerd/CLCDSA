#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define Di 3.1415926
#include<math.h>
#include<string>
#include<stack>
#define INF 0x3f3f3f3f
using namespace std;
ll  gcd(ll a,ll b)
{
    return a%b? gcd(b,a%b):b;
}
int a[200];
int main()
{    int m,sum=0,i,couts=0;
     scanf("%d",&m);
      for(i=0;i<m;i++)
      {
          scanf("%d",&a[i]);
          sum+=a[i];
      }
      int num=sum/(m);
      int maxs=0;
      int mins=INF,ss=0;
      if(num<0)
      {

          int couts=abs(sum%m)+1;
            i=0;
        while(i<couts)
        {
            int s=num-i;
             int ss=0;
            for(int j=0;j<m;j++)
          {
             ss+=pow(abs(s-a[j]),2);
          }
          if(ss<mins)
            mins=ss;

           i++;
         }
        cout<<mins<<endl;
         return 0;
      }
     for(i=num;i<=num+sum%m;i++)
     {     ss=0;

         for(int j=0;j<m;j++)
         {
             ss+=pow(abs(i-a[j]),2);
         }

         if(mins>ss)
          mins=ss;
     }

    printf("%d\n",mins);


 return 0;
}