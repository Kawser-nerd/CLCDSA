#include <stdio.h>
int main(void)
{
    long int n, i, cnt[5]={0}, march=0, ans=0, j, k;
    scanf("%ld", &n);
    char s[n][11];  
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
    }

    for(i=0;i<n;i++){
        if(s[i][0]=='M' && cnt[0]==0){
            cnt[0]++;
            march++;
        }
        else if(s[i][0]=='M') cnt[0]++;
        if(s[i][0]=='A' && cnt[1]==0){
            cnt[1]++;
            march++;
        }
        else if(s[i][0]=='A') cnt[1]++;
        if(s[i][0]=='R' && cnt[2]==0){
            cnt[2]++;
            march++;
        }
        else if(s[i][0]=='R') cnt[2]++;
        if(s[i][0]=='C' && cnt[3]==0){
            cnt[3]++;
            march++;
        }
        else if(s[i][0]=='C') cnt[3]++;
        if(s[i][0]=='H' && cnt[4]==0){
            cnt[4]++;
            march++;
        }
        else if(s[i][0]=='H') cnt[4]++;
    }

    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            for(k=j+1;k<5;k++){
                ans=ans+cnt[i]*cnt[j]*cnt[k];
            }
        }
    }

    printf("%ld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^