#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
   int n,a,b;
   scanf("%d%d%d",&n,&a,&b);
   if(n==1)
   {
       if(a==b)
        printf("1\n");
       else
       {
           printf("0\n");
       }
   }
   else
   {
       if(a>b)
        printf("0\n");
       else
        printf("%lld\n",(long long)(n-2)*(b-a)+1);
   }

    return 0;
}