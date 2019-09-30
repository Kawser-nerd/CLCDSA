#include <stdio.h>

int main(void){
    int n,ch,sm[200002],tt[200002],ans=0,s[100000],t[100000],c[100000];
    scanf("%d%d",&n,&ch);
    for (int i=0; i<n; i++){
        scanf("%d%d%d",&s[i],&t[i],&c[i]);
    }
    for (int i=0; i<200002; i++){
        sm[i]=0;
    }
    for (int i=1; i<=ch; i++){
        for (int j=0; j<200002; j++){
            tt[j]=0;
        }
        for (int j=0; j<n; j++){
            if (c[j]==i){
                tt[s[j]*2-1]++;
                tt[t[j]*2]--;
            }
        }
        for (int j=1; j<200002; j++){
            tt[j]+=tt[j-1];
        }
        for (int j=0; j<200002; j++){
            if (tt[j]>0){
                sm[j]++;
            }
        }
    }
    for (int i=0; i<200002; i++){
        if (ans<sm[i]){
            ans=sm[i];
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&ch);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&s[i],&t[i],&c[i]);
         ^