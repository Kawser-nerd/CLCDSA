#include <stdio.h>
#include <malloc.h>

int primes=0;
unsigned int* prime;

void genprime(void)
{
	prime=malloc(10000*sizeof(unsigned int));
	prime[0]=2;
	primes=1;
	for (unsigned int i=3;primes<10000;i+=2)
	{
		for (int t=0;t<primes;t++)
			if (!(i%prime[t])) goto notp;
		prime[primes++]=i;
		notp:;
	}
}

int factor(int* dig,int digits,int base,unsigned int max)
{
	for (int i=1;i<primes && prime[i]<max;i++)
	{
		int num=0,mul=1,p=prime[i];
		for (int j=0;j<digits;j++)
		{
			num=(num+dig[j]*mul)%p;
			mul=(mul*base)%p;
		}
		if (!num) return p;
	}
	return 0;
}

int iscoin(unsigned int n,int* f)
{
	int dig[32],digits=0;
	unsigned int t=n;
	while (t) {dig[digits++]=t&1;t>>=1;}
	for (int b=0;b<=8;b++)
	{
		f[b]=factor(dig,digits,b+2,n);
		if (!f[b]) return 0;
	}
	return 1;
}

void print(unsigned int n)
{
	int dig[32],digits=0;
	while (n) {dig[digits++]=n&1;n>>=1;}
	while (digits--) printf("%d",dig[digits]);
}

int main()
{
	freopen("C-large.in","rb",stdin);
	freopen("output.txt","wb",stdout);
	int cases;scanf("%d",&cases);
	genprime();
	for (int cs=1;cs<=cases;cs++)
	{
		printf("Case #%d:\n",cs);
		int n,j,f[9];scanf("%d%d",&n,&j);
		for (int i=(1<<(n-1))|1;j;i+=2)
		{
			if (iscoin(i,f))
			{
				print(i);
				for (int t=0;t<9;t++) printf(" %d",f[t]);
				printf("\n");
				j--;
			}
		}
	}
	free(prime);
}