#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(void){
    int N;
    scanf("%d",&N);
    char s[N][11];
    int i,j,k;
    long long c[5]={0,0,0,0,0};
    for(i=0;i<N;i++){
        scanf("%s",s[i]);
        if(s[i][0]=='M'){
            c[0]++;
        }else if(s[i][0]=='A'){
            c[1]++;
        }else if(s[i][0]=='R'){
            c[2]++;
        }else if(s[i][0]=='C'){
            c[3]++;
        }else if(s[i][0]=='H'){
            c[4]++;
        }
    }
    long long ans = 0;
    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            for(k=j+1;k<5;k++){
                ans += c[i]*c[j]*c[k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^