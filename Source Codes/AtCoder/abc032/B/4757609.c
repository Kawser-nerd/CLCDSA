#include <stdio.h>
#include <string.h>
int main(void){
    char s[301],t[301]={'\0'};
    int k,i,j,ans=0;
    scanf("%s%d",s,&k);
    if(k<=strlen(s)){
        for(i=0;i<strlen(s)-k+1;i++){
            for(j=0;j<k;j++){
                t[j]=s[i+j];
            }
            if(strstr(s,t)-s==i) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&k);
     ^