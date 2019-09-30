#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int sort(const void *A,const void *B){return *(long long*)A>*(long long*)B?1:0;}
 
int main(void){
    int n;
    scanf("%d",&n);
    long long a[n],v[n],ans=0;
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        v[i]=0;
    }
    qsort (a,n,sizeof(long long),sort);
    for (int i=31; i>=0; i--){
        long long count=0,back=n-1,sum=pow(2,i);
        while(count<back){
            if (v[count]==1){
                count++;
            } else if (v[back]==1){
                back--;
            } else if (a[count]+a[back]==sum){
                v[count]=1;
                v[back]=1;
                ans++;
                count++;
                back--;
            } else if (a[count]+a[back]<sum){
                count++;
            } else {
                back--;
            }
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^