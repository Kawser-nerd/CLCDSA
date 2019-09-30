#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define Di 3.1415926
#include<math.h>
#define INF 0x3f3f3f3f
using namespace std;
ll  gcd(ll a,ll b)
{
    return a%b? gcd(b,a%b):b;
}

int main()
{
  int a,b,c,t1=0,t2=0;
   cin>>a>>b>>c;
   if(a==5)
   {
       t1++;
   }
   if(a==7)
   {
       t2++;
   }

  if(b==5)
   {
       t1++;
   }
   if(b==7)
   {
       t2++;
   }
    if(c==5)
   {
       t1++;
   }
   if(c==7)
   {
       t2++;
   }
   if(t1==2&&t2==1)
    printf("YES\n");
   else
   {
       printf("NO\n");
   }



 return 0;
}