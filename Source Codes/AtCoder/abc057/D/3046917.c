#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

long long ncr(int a,int b){
    long long combinationans=1;
    for (int i=0; i<b; i++){
        combinationans=combinationans*(a-i)/(i+1);   
    }
    return (combinationans);
}

int sort(const void *a, const void *b){
    if( *(long long int*)a - *(long long int*)b < 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return -1;
    return 0;
}

int main(void){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    long long v[n],sum=0;
    for (int i=0; i<n; i++){
        scanf("%lld",&v[i]);
    }
    qsort (v,n,sizeof(long long),sort);
    
    for (int i=0; i<a; i++){
        sum+=v[i];
    }
    double ans=(double)sum/(double)a;
    
    long long ans2=0;
    if (v[0]!=v[a-1]){
        int countn=0,countr=0;
        for (int j=0; j<n; j++){
            if (v[a-1]==v[j]){
                countn++;
                if (j<a){
                    countr++;
                }
            }
        }
        ans2=ncr(countn,countr);   
    } else {
        int count=0;
        for (int j=0; j<n; j++){
            if(v[0]==v[j]){
                count++;
            }
        }
        for (int j=a; j<=b; j++){
            ans2+=ncr(count,j);
        }
    }
    printf("%lf\n%lld\n",ans,ans2);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&v[i]);
         ^