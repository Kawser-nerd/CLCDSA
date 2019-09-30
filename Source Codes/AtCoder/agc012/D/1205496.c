#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define NITEM(arr) (sizeof(arr)/sizeof(arr[0]))
#define MODU 1000000007LL

#define N_MAX 200000


typedef long long ll;

typedef struct
{
	int c, w;
}ball_t;


ball_t ball[N_MAX+1];
int c_num[N_MAX+1];
int movable[N_MAX+1];
ll factrial[N_MAX+1];

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


int cmp(const void *pa, const void *pb)
{
	const ball_t *a, *b;

	a=pa;
	b=pb;
	if(a->w<b->w) return -1;
	return (a->w>b->w);
}


int cmp2(const void *pa, const void *pb)
{
	const ball_t *a, *b;

	a=pa;
	b=pb;
	if(a->c<b->c) return -1;
	if(a->c>b->c) return 1;

	if(a->w<b->w) return -1;
	return (a->w>b->w);
}


ll mod_inv(ll a, ll b)
{
	ll n, ret=1LL;

	for(n=b-2;n>0;n>>=1)
	{
		if(n&1) ret=(ret*a)%b;
		a=(a*a)%b;
	}
	return ret;
}


ll calc(int c_num[], int n)
{
	int i, j;
	ll u, l;

	if(factrial[0]==0)
	{
		factrial[0]=1;
		for(i=1;i<=N_MAX;i++)
		{
			factrial[i]=(factrial[i-1]*i)%MODU;
		}
	}

	l=u=1;
	for(i=j=0;i<n;i++)
	{
		if(c_num[i]==0) continue;

		l=(l*factrial[c_num[i]])%MODU;
		j+=c_num[i];
	}
	u=factrial[j];
	return (u*mod_inv(l, MODU))%MODU;
}


int main(void)
{
	int N, X, Y;
	int i, second, light;

if(0)
{
	ll x=123;
	printf("%lld\n", (x*mod_inv(x, MODU))%MODU);
	return 1;
}


	while(scanf("%d%d%d", &N,&X,&Y)==3)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d%d", &ball[i].c, &ball[i].w);
		}

		qsort(ball, N, sizeof(ball[0]), cmp2);
		light=0;
		for(i=1;i<N;i++)
		{
			if(ball[light].c==ball[i].c)
			{
				if(ball[light].w+ball[i].w<=X)
				{
					ball[i].w=ball[light].w;
				}
			}
			else
			{
				light=i;
			}
		}

		qsort(ball, N, sizeof(ball[0]), cmp);

		for(second=1;second<N;second++)
		{
			if(ball[second].c!=ball[0].c) break;
		}

		if(second>=N)
		{
			printf("1\n");
			continue;
		}

		memset(movable, 0, sizeof(movable));
		for(i=0;i<N;i++)
		{
			if(ball[0].c!=ball[i].c)
			{
				if(ball[0].w+ball[i].w<=Y) movable[i]=1;
			}
			if(ball[second].c!=ball[i].c)
			{
				if(ball[second].w+ball[i].w<=Y) movable[i]=2;
			}
		}

		memset(c_num, 0, sizeof(c_num));
		for(i=0;i<N;i++)
		{
			if(movable[i]) c_num[ball[i].c]++;
		}
		printf("%d\n", (int)calc(c_num+1, N));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:120:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &ball[i].c, &ball[i].w);
    ^