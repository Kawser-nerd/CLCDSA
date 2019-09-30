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


   int n,sum=0;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       sum+=i;

   }

    cout<<sum<<endl;



 return 0;
}