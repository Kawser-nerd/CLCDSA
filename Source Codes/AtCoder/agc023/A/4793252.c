#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    if(*(long long *)a>*(long long *)b)return 1;
    return -1;
}
int main()
{   int n;
    scanf("%d",&n);
    long long a[n],s[200001]={0};
    s[0]=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        s[i+1]=s[i]+a[i];
    }
    long long cnt=1;
    long long ans=0;
    qsort(s,n+1,sizeof(long long),compare);
    for(int i=0;i<n;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }else{
            ans+=cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    ans+=(cnt*(cnt-1)/2);
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^