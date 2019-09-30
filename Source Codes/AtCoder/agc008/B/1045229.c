#include<stdio.h>
int a[100005];

long long int sum[100005],sum2[100005];
long long int zet(long long int a){
    if(a>=0)return a;
    else return 0;
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int i;
    for(i=0;i<=n-1;i++)scanf("%d",&a[i]);
    sum[0]=a[0];
    sum2[0]=zet(a[0]);
    for(i=1;i<=n-1;i++){
        sum[i]=sum[i-1]+a[i];
        sum2[i]=sum2[i-1]+zet(a[i]);
    }
    
    
    long long int max=sum2[n-1]-sum2[k-1]+zet(sum[k-1]);
    for(i=1;i<=n-k;i++){
        long long int gou=0;
        gou+=sum2[n-1]-sum2[i+k-1]+zet(sum[i+k-1]-sum[i-1])+sum2[i-1];
        if(max<gou)max=gou;
    }
    printf("%lld",max);
    
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^
./Main.c:16:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<=n-1;i++)scanf("%d",&a[i]);
                        ^