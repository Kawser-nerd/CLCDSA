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
    int i,T,x,A[10][20],E,R,N,V[20];
    int j,t,newval,eg;
    si(T);
    for ( x=1;x<=T;x++)
    {
        si(E);si(R);si(N);
        memset(A,0,sizeof(int)*10*20);
        for(i=0;i<N;i++)
        {
            si(V[i]);
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<=E;j++)
            {
                for(t=0;t<=j;t++)
                {
                    newval=A[j][i]+V[i]*t;
                    eg=(j-t+R);
                    if(eg>E)
                        eg=E;
                    A[eg][i+1]=max(newval,A[eg][i+1]);
                }
            }
        }
        eg=A[0][N];
        for(j=1;j<=E;j++)
        {
            if(A[j][N]>eg)
                eg=A[j][N];
        }
        printf("Case #%d: %d\n",x,eg);
    }
	return 0;
}

