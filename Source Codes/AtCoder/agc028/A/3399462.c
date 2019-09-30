#include<stdio.h>
#include<string.h>
void qz(long long a,long long b,long long*bs,long long*ys)
{
	long long r,t,j;
	j=a*b;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	*bs=j/a;
	*ys=a; 
}
int main()
{
	char s[100001],t[100001];
	int i;
	long long bs,ys,n,m;
	scanf("%ld",&n);
	scanf("%ld",&m);
	getchar();
	gets(s);
	gets(t);
	if(s[0]!=t[0])
	{
		printf("-1\n");
		return 0;
	}
	qz(n,m,&bs,&ys);
	if(n>m&&n%m==0)
	{
		for(i=1;i<m;i++)
		{
			if(s[m/n*i]!=t[i])
			printf("-1\n");
			return 0;
		}
	}
	else if(m>n&&m%n==0)
	{
		for(i=1;i<m;i++)
		{
			if(t[m/n*i]!=s[i])
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<=ys;i++)
	{
		if(s[bs/m*i]!=t[bs/n*i])
		{
			printf("-1\n");
			return 0;
		}
	}
		printf("%ld",bs);
	return 0;
	 
} ./Main.c: In function ‘main’:
./Main.c:27:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%ld",&n);
        ^
./Main.c:28:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%ld",&m);
        ^
./Main.c:30:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
./Main.c:64:10: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%ld",bs);
          ^
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&m);
  ^
/tmp/cc8qmwxT.o: In function `main':
Main.c:(.text.startup+0x4d): warning: the `gets' function is dangerous and s...