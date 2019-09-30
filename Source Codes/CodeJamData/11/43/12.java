#include <math.h>
#include <stdio.h>
typedef unsigned int uint;
typedef long long ll; 

bool primepow2(ll n)
{
    ll ubound = (long long)ceil(sqrt((long double)n));
    for (ll i=2; i<=ubound; i++)
    {
        if (n%i==0) {
            n/=i;
            if (n==1) return false;
            while (n%i==0) {
                n/=i;
            }
            if (n!=1)
                return false;
            return true;
        }
    }    
    return false;
}

int solve()
{
    long long n;
    scanf("%Ld", &n);
    if (n==1) {
        return 0;
    }
        
    uint count = 1;
    for (ll i=2; i<=n; i++)
    {
        if (primepow2(i))
            count++;
    }
    return count;
    
}

int main()
{
    int c;
    scanf("%d", &c);
    for (int i=0; i<c; i++)
        printf("Case #%d: %d\n", i+1, solve());
}