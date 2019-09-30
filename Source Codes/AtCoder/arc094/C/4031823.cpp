#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;
long long  a[200100],b[200100];
int main ()
{
    int n;
    while(~scanf("%d",&n))
    {
        long long ma=1e17,dd,bb=0;
        long long sum =0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a[i],&b[i]);
            sum+=a[i];
            if(a[i]>b[i])
            {
                ma=min(ma,b[i]);
            }
            else if(a[i]==b[i])
                bb+=a[i];
        }
        if(ma==1e17)
            printf("%lld\n",0ll);
        else
            printf("%lld\n",sum-ma);
    }
    return 0;
}


//int len,a[10010];
//bool vis[10010]={0};
//void init()
//{
//    a[++len]=2;
//    for(int i=3;i<=1000;i+=2)
//    {
//        if(!vis[i])
//            a[++len]=i;
//        for(int j=i;j;j+=2)
//    }
//}
//int main()
//{
//    len =0;
//    init();
//    int a,b;
//    while(~scanf("%d %d",&a,&b))
//    {
//
//    }
//    return 0;
//}