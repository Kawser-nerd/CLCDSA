#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            int te;
            scanf("%d",&a[i]);
        }
        if(n<4)
        {
            printf("0\n");
            continue;
        }
        sort(a,a+n);
        int c=0;
        int flag=0;
        int k[3];
        for(int i=n-2; i>=0; i--)
        {
            if(a[i+1]==a[i])
            {
                k[c]=a[i];
                i--;
                c++;
            }
            if(c==2)
            {
                break;
            }
            if(i==0)
            {
                printf("0\n");
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            long long r;
            r=k[0]*k[1];
            printf("%lld\n",r);
//            printf("%d×%d rectangle can be formed.\n",k[1],k[0]);
        }
    }
}