#include<iostream>
#include<cmath>
using namespace std;
const int MAXN = 2e5 + 100;
long long x,sum[MAXN],n,min_,i;
int main()
{
    cin>>n;
    sum[0]=0;
    for(i=1;i<=n;i++)
       {
           cin>>x;
           sum[i]=sum[i-1]+x;
       }
    min_=abs(2*sum[1]-sum[n]);
   for(i=2;i<n;i++)
   {
       min_=min_<abs(2*sum[i]-sum[n])?min_:abs(2*sum[i]-sum[n]);
   }
    cout<<min_;
}