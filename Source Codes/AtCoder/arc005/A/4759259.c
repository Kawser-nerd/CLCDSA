#include <stdio.h>
#include <string.h>
int main(void){
    int n,i,ans=0;
    char s[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        if(strcmp(s,"TAKAHASHIKUN")==0 || strcmp(s,"Takahashikun")==0 || strcmp(s,"takahashikun")==0 || strcmp(s,"TAKAHASHIKUN.")==0 || strcmp(s,"Takahashikun.")==0 || strcmp(s,"takahashikun.")==0) ans++;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s);
         ^