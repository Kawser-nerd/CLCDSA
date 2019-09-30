#include<stdio.h>
#include<string.h>

typedef long long ll;

ll h[2505];
void main()
{
    ll t, n, i, j, a, k;
    freopen("B-large.in", "r", stdin);
    freopen("B-large-output.txt", "w", stdout);
    scanf("%lld", &t);
    k=1;
    while(k<=t)
    {
        scanf("%lld", &n);
        for(i=1; i<=2500; i++)
        {
            h[i]=0;
        }
        for(i=0; i<2*n-1; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lld", &a);
                h[a]++;
            }
        }
        printf("Case #%lld:", k);
        for(i=1; i<=2500; i++)
        {
            if(h[i]%2!=0)
            {
                printf(" %lld", i);
            }
        }
        printf("\n");
        k++;
    }

}
