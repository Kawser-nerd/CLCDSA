#include <stdio.h>
int main(void){
    long long n,ans=0,l=0,r=0;
    scanf("%lld",&n);
    long long a[n];
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
    }
    long long s=a[0],x=a[0];
    for (l=0; l<n; l++){
        while(r+1<n && (s+a[r+1])==(x^a[r+1])){
            r++;
            s+=a[r];
            x^=a[r];
        }
        ans+=r-l+1;
        if (r==l){
            r++;
            s=a[l+1];
            x=a[l+1];
        } else {
            s=s-a[l];
            x=x^a[l];
        }
    }
    printf("%lld\n",ans);
    return 0;    
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^