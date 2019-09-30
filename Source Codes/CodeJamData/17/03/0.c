#include <stdio.h>

typedef long long int ll;

int main(void)
{
    int t;
    scanf("%d", &t);
    int curcase = 0;
    while (t != curcase)
    {
        ll n, rem;
	scanf("%llu %llu", &n, &rem);
	ll partsize = n;
	ll smcount = 1;
	ll bigcount = 0;
	while (1)
	{
	    rem -= bigcount;
	    if (rem <= 0)
	    {
	        printf("Case #%d: %llu %llu\n", curcase + 1, (partsize + 1) / 2, partsize / 2);
	    	curcase++;
		break;
	    }
	    ll newpartsize = (partsize - 1) / 2;
	    ll newsmcount = (partsize & 1) ? bigcount : 0;
	    ll newbgcount = (partsize & 1) ? bigcount : 2 * bigcount;
	    rem -= smcount;
	    if (rem <= 0)
	    {
	        printf("Case #%d: %llu %llu\n", curcase + 1, partsize / 2, (partsize - 1) / 2);
		curcase++;
		break;
	    }
	    newsmcount += (partsize & 1) ? 2 * smcount : smcount;
	    newbgcount += (partsize & 1) ? 0 : smcount;
	    partsize = newpartsize;
	    smcount = newsmcount;
	    bigcount = newbgcount;
	}
    }
    return 0;
}
