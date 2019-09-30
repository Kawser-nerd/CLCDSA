#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>
#define swap(a,b) (a)=(a)+(b)-((b)=(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define pw printf(" ")
#define pn printf("\n")
#define pi(a) printf("%d",(a))
#define si(a) scanf("%d",(&a))
#define FORD(i,a,b) for((i)=(a);(i)>=(b);(i)++)
#define chkpowtwo(a) (!((a)&((a)-1)))

//int power(int a,int b)					//make long long if unsure it can handle or not!!!!
//{int s=1;while(b){if(b&1)s*=a;a=a*a;b=b/2;}return s;}

//int powermodp(int a,int b,int p)
//{int s=1;while(b){if(b&1){s*=a;s=s%p;}a=a*a;a=a%p;b=b/2;}return s%p;}

int main()
{
    int i,T;
    long long int n,r,t,st,end,tmp;
    si(T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&r);scanf("%lld",&t);
        st=1;end=min(t/r,sqrt(t)+1);
        while(st!=end)
        {
            n=(st+end)/2;
            tmp=2*n*n+2*n*r-n;
            if(tmp<0)
            {
                end=n;
                continue;
            }
            if(tmp>=t)
                end=n;
            else if(tmp<t)
                st=n+1;
        }
        n=st+1;
        tmp=2*n*n+2*n*r-n;
        while(tmp>t)
        {
            n--;
            tmp=2*n*n+2*n*r-n;
        }
        printf("Case #%d: %lld\n",i,n);
    }
	return 0;
}

