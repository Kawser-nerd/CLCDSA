#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int AscendingSort(const void *A,const void *B){return *(long long*)A>*(long long*)B?1:0;}

int main(void){
    int n;
    scanf("%d",&n);
    long long a[n],v[n],ans=0,sum=pow(2,31);
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        v[i]=0;
    }
    qsort (a,n,sizeof(long long),AscendingSort);
    
    for (int i=0; i<=31; i++){
        int count=0,back=n-1;
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
        sum/=2;
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