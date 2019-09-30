#include<stdio.h>
#include<math.h>

int main()
{
    long long int n,a[105],b[505],i,j,k,mx=-101,mn=101,s=0;

    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]>=mx){
            mx=a[i];
        }
    }
    for(i=0;i<n;i++){
        if(a[i]<=mn){
            mn=a[i];
        }
    }
    for(i=mn,k=1;i<=mx;i++,k++){
        for(j=0;j<n;j++){
            s=s+(a[j]-i)*(a[j]-i);
        }
        b[k]=s;
        s=0;
    }
    s=100000000000000000;
    for(i=1;i<k;i++){
        if(b[i]<=s){
            s=b[i];
        }
    }
    printf("%lld\n",s);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^