#include <stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    char po[100],pu[100];
    scanf("%s",po);
    scanf("%s",pu);
    long long int ans;
    int back;
    for(int i=0;i<N;i++){
        if(i==0){
            if(po[0]==pu[0]){ans=3;back=0;}
            else {
                ans=6;
                i++;
                back=1;
            }
        }
        else {
            if(po[i]==pu[i]){
                if(back==0)ans*=2;
                back=0;
            }
            else {
                if(back==0)ans*=2;
                else ans*=3;
                back=1;
                i++;
            }
        }
        ans%=1000000007;
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",po);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",pu);
     ^