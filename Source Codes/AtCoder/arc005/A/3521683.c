#include <stdio.h>
#include <string.h>
int main(void){
    int n,ans=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        char w[120];
        scanf("%s",w);
        if (strcmp(w,"TAKAHASHIKUN")==0 || strcmp(w,"Takahashikun")==0 || strcmp(w,"takahashikun")==0){
            ans++;
        }
        if (strcmp(w,"TAKAHASHIKUN.")==0 || strcmp(w,"Takahashikun.")==0 || strcmp(w,"takahashikun.")==0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",w);
         ^