#include <stdio.h>

typedef long long int ll;

ll invert(ll n)
{
    ll inv = 0;
    
    while(n)
    {
        inv *= 10;
        inv += n%10;
        n /= 10;
    }
    
    return inv;
}

int ndigs(ll n)
{
    int nd = 0;
    
    while(n)
    {
        nd++;
        n /= 10;
    }
    
    return nd;
}

int p0w10(int e)
{
    int i;
    ll p = 1;

    for(i = 0; i < e; i++)
        p *= 10;
    
    return p;
}

int compute(ll n)
{
    int sum = 1;

    while(n > 1)
    {
        int nd = ndigs(n)+1;
        ll p10 = p0w10(nd/2);
        ll mod = n%p10;

        //printf("%lld %lld %d\n", n, p10, sum);
        
        if(mod == 1)
        {
            ll inv = invert(n);
            if(n > inv)
                n = invert(n);
            else 
                n--;
            sum++;
            continue ;
        }
        
        if(mod == 0)
        {
            n--;
            sum++;
            continue ;
        }
        
        n -= (mod-1);
        sum += (mod-1);
    }
    
    return sum;
}

int main()
{
    int T, cont = 0;
    
    scanf("%d\n", &T);
    while(T--)
    {
        ll n;
        
        scanf("%lld\n", &n);
        
        printf("Case #%d: %d\n", ++cont, compute(n));
    }
    
return 0;
}
