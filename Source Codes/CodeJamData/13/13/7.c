#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

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
    int k,T,R,N,M,K,i,tmp,A[6],count=0;
    si(T);
    si(R);si(N);si(M);si(K);
    printf("Case #1:\n");
    for(i=0;i<R;i++)
    {
        memset(A,0,24);
        count=0;
        for(k=0;k<K;k++)
        {
            si(tmp);
            if(tmp%2==0)
                A[2]=1;
            if(tmp%3==0)
                A[3]=1;
            if(tmp%4==0)
                A[4]=1;
            if(tmp%5==0)
                A[5]=1;
        }
        if(A[5])
        {
            count++;
            pi(5);
        }
        if(A[4])
        {
            count++;
            pi(4);
        }
        if(A[3])
        {
            count++;
            pi(3);
        }
        if(count<N&&A[2])
        {
            count++;
            pi(2);
        }
        while(count<N)
        {       pi(2);
            count++;
        }
        pn;
    }
	return 0;
}

