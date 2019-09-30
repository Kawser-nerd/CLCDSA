#include <stdio.h>
int main(void){
    int N,K;
    scanf("%d %d",&N,&K);
    int s[N+1];
    s[0]=1;
    for(int i=1;i<=N;i++){scanf("%d",&s[i]);if(s[i]==0){printf("%d\n",N);return 0;}}
    long long int yamadaishomo=1;
    int a=1,b=1;
    int ans=0;
    int buri=0;
    while(a<=N){
        yamadaishomo*=(long long int)s[a];
        buri++;
        if(yamadaishomo>K){
            while(b<a&&yamadaishomo>(long long int)K){
                yamadaishomo/=(long long int)s[b];
                b++;
                buri--;
            }
            if(b==a&&yamadaishomo>(long long int)K){
                b++;
                yamadaishomo=(long long int)s[a];
            }
        }
        else if(ans<buri)ans=buri;
        a++;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&K);
     ^
./Main.c:7:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=1;i<=N;i++){scanf("%d",&s[i]);if(s[i]==0){printf("%d\n",N);return 0;}}
                           ^