#include <stdio.h>
#include <stdlib.h>

/*#define DEBUG*/

typedef long long ll;

#define MOD 10007


struct pair {
	ll x;
	ll y;
};

struct pair diry[10];
ll m,n;
int der;


ll result;

ll vybrane[10];
ll inv[MOD];

void geninvers()
{
	ll i,j;
	ll prod;
	for (i=1;i<MOD;i++) {
		prod = 0;
		for (j=0;prod != 1;j++) {
			prod += i;
			prod %= MOD;
		}
		inv[j]=i;
	}
}


ll choose(ll n, ll k)
{
	ll vysl = 1;
	ll nul = 0;
	ll i;

	for (i=n-k+1; i<=n; i++) {
		while (i%MOD==0) {
			i/=MOD;
			nul++;
		}
		vysl *= i;
		vysl %= MOD;
	}

	for (i=1; i<=k; i++) {
		while (i%MOD==0) {
			i/=MOD;
			nul--;
		}
		vysl *= inv[i%MOD];
		vysl %= MOD;
	}

	return vysl;

#if 0
	ll res = 1;
	ll i;
	for (i=1; i<=k; i++) {
		res *= n;
		n--;
		res /= i;
	}
	return res;
#endif
}


ll volne(ll m,ll n)
{
#ifdef DEBUG
	printf("[%lld %lld]",m,n);
#endif
	ll i,j,k;
	if ((m==0) && (n==0)) return 1;
	if ((m<=0) || (n<=0)) return 0;
	i = m+n;
	if (i%3 != 0)
		return 0;
	i /= 3;
	if ((m-i) < 0 || (n-i) < 0) 
		return 0;
	return choose (i,m-i);
}



void vybrano()
{
	int signum = 1;
	ll x0 = 1, y0 = 1;
	int i;

	ll meziv = 1;

	for (i=0;i<der;i++) {
		if (vybrane[i] == 1) {
			signum *= -1;
#ifdef DEBUG
			printf("(%lld,%lld):",diry[i].x,diry[i].y);
#endif
			meziv *= volne(diry[i].x-x0, diry[i].y-y0);
		        meziv %= MOD;
			x0 = diry[i].x;
			y0 = diry[i].y;
		}
	}
	meziv *= volne(m-x0,n-y0);
	meziv %= MOD;
#ifdef DEBUG
			printf("%lld\n",meziv*signum);
#endif

	result = (result + meziv*signum + MOD) % MOD;
}


void vybirej(int k)
{
	int i;

	if (k==der) {
		vybrano();
		return;
	}
	vybrane[k] = 0;
	vybirej(k+1);
	vybrane[k] = 1;
	vybirej(k+1);
}

int compdir(const void *a, const void *b)
{
	ll i1 = ((struct pair*)a)->x;
	ll i2 = ((struct pair*)b)->x;
	if (i1<i2) return -1;
	if (i1==i2) return 0;
	return 1;
}


void runcase()
{
	int i;
	scanf(" %lld %lld %d", &m,&n,&der);
	for (i=0;i<der;i++) {
		scanf(" %lld %lld", &(diry[i].x), &(diry[i].y));
	}

	qsort(diry,der,sizeof(struct pair), compdir);
	/*
	for (i=0;i<der;i++) {
		printf(" (%lld %lld)", (diry[i].x), (diry[i].y));
	}
	*/

	result = 0;
	vybirej(0);
	printf("%lld\n",result);
}

int main()
{
	int cases, i;

	geninvers();

	scanf(" %d", &cases);
	for (i=1; i<=cases; i++) {
		printf("Case #%d: ",i);
		runcase();
	}
	return 0;
}
