#include <stdio.h>
int main(void){
    long long int N;
    scanf("%lld",&N);
    long long int a[N];
    for(int i=0;i<N;i++)scanf("%lld",&a[i]);
    int flag=0;
    long long int ans=0;
    while(flag==0){
        flag=1;
        for(int i=0;i<N;i++){
            long long int tmp=a[i]/N;
            if(tmp!=0){
                flag=0;
                a[i]-=tmp*N;
                ans+=tmp;
                for(int j=0;j<N;j++){
                    if(i!=j)a[j]+=tmp;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&N);
     ^
./Main.c:6:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%lld",&a[i]);
                         ^