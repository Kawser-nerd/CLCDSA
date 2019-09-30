#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define pi 3.141592653589793

int gcd(int a,int b){
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int cmpfunc(const void *x, const void *y){
    const int *a = (const int *)x;
    const int *b = (const int *)y;
    if(a[0] == b[0])
        return a[1] - b[1];
    else
        return b[0] - a[0];
}

int cmp (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b == 0 )
        return 0;
}

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int main(void){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        int r1[n],h1[n];
        int j;
        for(j=0;j<n;j++){
            scanf("%d %d",&r1[j],&h1[j]);
        }
        long long r[n],h[n];int zzz[n][2];
        for(j=0;j<n;j++) {
            zzz[j][0]=r1[j];
            zzz[j][1]=h1[j];
        }
        qsort(zzz,n,sizeof(zzz[0]),cmpfunc);
        for(j=0;j<n;j++){
            r[j]=(long long)zzz[j][0];
            h[j]=(long long)zzz[j][1];
        }

        long long rh[n];
        for(j=0;j<n;j++)
            rh[j]=r[j]*h[j];
        int base;
        long long max_area=0,ans;
        for(base=0;base<=n-k;base++){
            ans=0;
            ans+=r[base]*r[base]+2*rh[base];
            long long a[n-base-1];
            for(j=0;j<n-base-1;j++)
                a[j]=rh[j+base+1];
            qsort(a,n-base-1,sizeof(long long),cmp);
            for(j=0;j<k-1;j++)
                ans+=2*a[j];
            if(ans>max_area) max_area=ans;
        }
        printf("Case #%d: %.9f\n",i+1,(double)1.0*max_area*pi);
    }
    return 0;
}
