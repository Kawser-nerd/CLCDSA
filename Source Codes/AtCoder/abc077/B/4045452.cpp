#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <queue>
using namespace std;
int main()
{
    long long m,i,sum,flag;
    while(~scanf("%lld",&m))
    {
        for(i=1; i<=m; i++)
        {
            sum=i*i;
            if(sum==m)
            {
                flag=i;
                break;
            }
            if(sum>m)
            {
                flag=i-1;
                break;
            }
        }
        flag*=flag;
        printf("%lld\n",flag);
    }
    return 0;
}