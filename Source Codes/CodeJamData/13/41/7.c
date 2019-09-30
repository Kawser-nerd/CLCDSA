#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODULUS 1000002013
#define MAXM          1000

struct a
{
    int o, e, p;
};

int cmp_o(const void *p, const void *q)
{
    const struct a *a = p, *b = q;
    return a->o < b->o ? -1 : a->o > b->o ? 1 : 0;
}

int cmp_e(const void *p, const void *q)
{
    const struct a *a = p, *b = q;
    return a->e < b->e ? -1 : a->e > b->e ? 1 : 0;
}

long long price(int n, int d, int p)
{
    long long result = n * (n + 1LL) / 2;
    result -= (n-d) * (n-d + 1LL) / 2;
    result %= MODULUS;
    result = (result * p) % MODULUS;
    return (int)result;
}

int main()
{
    int t, c;
    int n, m;
    struct a a[MAXM];
    struct a b[MAXM];
    int k, otot[MAXM], ptot[MAXM];
    long long shouldpay, couldpay, y;
    int i, j, p;
    
    scanf("%d", &t);
    for (c=1; c<=t; c++)
    {
        scanf("%d%d", &n, &m);
        shouldpay = couldpay = 0;
        for (i=0; i<m; i++)
        {
            scanf("%d%d%d", &a[i].o, &a[i].e, &a[i].p);
            shouldpay += price(n, a[i].e - a[i].o, a[i].p);
            shouldpay %= MODULUS;
        }
        
        memcpy(b, a, m * sizeof(struct a));
        qsort(a, m, sizeof(struct a), cmp_o);
        qsort(b, m, sizeof(struct a), cmp_e);
        i = j = 0;
        k = 0;
        while (j != m)
        {
            while (i != m && a[i].o <= b[j].e)
            {
                otot[k] = a[i].o;
                ptot[k] = a[i].p;
                i++, k++;
            }
            
            p = ptot[k-1] < b[j].p ? ptot[k-1] : b[j].p;
            couldpay += price(n, b[j].e - otot[k-1], p);
            couldpay %= MODULUS;
            
            if ((ptot[k-1] -= p) == 0)
                k--;
            if ((b[j].p -= p) == 0)
                j++;
        }
        
        y = (shouldpay - couldpay) % MODULUS;
        if (y < 0)
            y += MODULUS;
        
        printf("Case #%d: %lld\n", c, y);
    }
    return 0;
}
