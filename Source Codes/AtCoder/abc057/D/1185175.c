#include<stdio.h>
#include<stdlib.h>

typedef long long ll;


ll gcd(ll a, ll b)
{
	ll c;
	while((c=a%b))
	{
		a=b;
		b=c;
	}
	return b;
}

ll nCm(int n, int m)
{
	int i;
	ll u=1, l=1, d;

	if(m*2>n)
	{
		m=n-m;
	}

	for(i=0;i<m;i++)
	{
		d=gcd(u, l);
		u/=d;
		l/=d;

		d=gcd(l, n-i);
		u*=(n-i)/d;
		l/=d;

		d=gcd(u, m-i);
		u/=d;
		l*=(m-i)/d;
	}
	return u/l;
}


int cmp(const void *a, const void *b)
{
	const ll *pa, *pb;
	pa=a;
	pb=b;
	if(*pa>*pb) return -1;
	return (*pa<*pb);
}


int main(void)
{
	int N, A, B, i, l, r;
	ll v[50], sum, pat;
	double d;

	while(scanf("%d%d%d", &N, &A, &B)==3)
	{
		for(i=0;i<N;i++)
		{
			scanf("%lld", &v[i]);
		}
		qsort(v, N, sizeof(v[0]), cmp);

		for(l=A-1;v[l-1]==v[A-1] && l-1>=0;l--)
			;

		for(r=A-1;v[r+1]==v[A-1] && r+1<N;r++)
			;

		if(v[0]!=v[A-1]) B=A;

		sum=0;
		for(i=0;i<A;i++) sum+=v[i];
		if(sum>N*10)
		{
			d=sum-sum/(A*10)*(A*10);
			printf("%lld", sum/(A*10));
			printf("%.6f\n", d/A);
		}
		else
		{
			printf("%.6f\n", (double)sum/A);
		}

		pat=0;
		for(i=A-1;i<B && i<=r;i++)
		{
			pat+=nCm(r-l+1, i-l+1);
		}
		printf("%lld\n", pat);
	}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:66:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld", &v[i]);
    ^