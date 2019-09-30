#include <stdio.h>
#include <string.h>

int main(void){
    char po[10000];
    scanf("%s",po);
    int s=strlen(po);
    int x[2];
    scanf("%d %d",&x[0],&x[1]);
    int flag=0;
    int buri[2][10000]={};
    buri[0][0]=1;
    buri[1][0]=1;
    int firstflag=1;
    int sum[2]={};
    int count=0;
    for(int i=0;i<s;i++){
        if(po[i]=='F'&&firstflag==1){
            x[flag]--;
        }
        else if(po[i]=='T'){
            for(int i=9999;i>=0;i--){if(buri[flag][i]==1)buri[flag][i+count]=1;}
            sum[flag]+=count;
            flag^=1;
            count=0;
            firstflag=0;
        }
        else if(i==s-1){
            count++;
            for(int i=9999;i>=0;i--){if(buri[flag][i]==1)buri[flag][i+count]=1;}
            sum[flag]+=count;
        }
        else count++;
    }
    int ans[2]={1,1};
    for(int i=0;i<2;i++){
        if(sum[i]+x[i]<0)ans[i]=0;
        else if((sum[i]+x[i])%2==1)ans[i]=0;
        else if(buri[i][(sum[i]+x[i])/2]==0)ans[i]=0;
    }
    if(ans[0]==1&&ans[1]==1)printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",po);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&x[0],&x[1]);
     ^