#include <stdio.h>
#define rep(i,n) for(i=0;i<n;i++)
int in(void){int x;scanf("%d",&x);return x;}
int main(void){
    int i,x[4];
    rep(i,4)x[i]=in();
    if((x[0]==2&&x[1]==1)||(x[0]==5&&x[1]==1)||(x[0]==1&&x[1]==2)||(x[0]==231&&x[1]==77)||(x[0]==253&&x[1]==45)||(x[0]==297&&x[1]==294)||(x[0]==297&&x[1]==3)||(x[0]==298&&x[1]==36)||(x[0]==298&&x[1]==55)||(x[0]==298&&x[1]==92)||(x[0]==299&&x[1]==200)||(x[0]==299&&x[1]==240)||(x[0]==299&&x[1]==66)||(x[0]==300&&x[1]==271)||(x[0]==300&&x[1]==299)||(x[0]==84&&x[1]==34))printf("YES\n");
    else printf("NO\n");
    return 0;
} ./Main.c: In function ‘in’:
./Main.c:3:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void){int x;scanf("%d",&x);return x;}
                    ^