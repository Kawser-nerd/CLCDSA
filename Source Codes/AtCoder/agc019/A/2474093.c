#include<stdio.h>

int main()
{
    long long int q,h,s,d,n,i,j,v[4],cost,a;
    scanf("%lld %lld %lld %lld",&q,&h,&s,&d);
    scanf("%lld",&n);
    v[0]=8*q;
    v[1]=4*h;
    v[2]=2*s;
    v[3]=d;
    for(i=0;i<=3;i++){
    	for(j=0;j<=2-i;j++){
    		if (v[j]>v[j+1]) {
    			a=v[j];
    			v[j]=v[j+1];
    			v[j+1]=a;
    		}
    	}
    }
    if(v[0]!=d) cost=n*v[0]/2;
    else cost=(n-n%2)*v[0]/2+(n%2)*v[1]/2;
    printf("%lld\n",cost);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld",&q,&h,&s,&d);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^