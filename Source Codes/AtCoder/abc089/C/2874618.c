#include<stdio.h>
int main(void){
    long long int mn=0,an=0,rn=0,cn=0,hn=0,ansm,ansa,ansr;
    int n,i;
    char s[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        if(s[0]=='M'){
            mn++;
        }
        if(s[0]=='A'){
            an++;
        }
        if(s[0]=='R'){
            rn++;
        }
        if(s[0]=='C'){
            cn++;
        }
        if(s[0]=='H'){
            hn++;
        }
    }
    ansm=mn*an*rn + mn*an*cn + mn*an*hn + mn*rn*cn + mn*rn*hn + mn*cn*hn;
    ansa=an*rn*cn + an*rn*hn + an*cn*hn;
    ansr=rn*cn*hn;
    printf("%lld\n",ansm+ansa+ansr);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s);
         ^