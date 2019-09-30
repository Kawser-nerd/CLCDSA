#include <stdio.h>
#include <string.h>

int main(void){
    char pass[301];
    scanf("%s",pass);
    int n;
    scanf("%d",&n);
    int len = strlen(pass);
    int count = len - n +1;
    int anscount = 0;
    if(n <= len){
        anscount = 1;
        char ans[count][n+1];
        memset(ans,'\0',sizeof(char) * (n+1) * count);
        for(int i = 0;i<count;i++){
            for(int j = 0;j<n;j++){
                ans[i][j] = pass[i+j];
            }
            for(int j = 0;j<i;j++){
                // printf("%s\n",ans[i]);
                // printf("%s\n",ans[j]);
                if(strstr(ans[i],ans[j]) != NULL){
                    // printf("no\n");
                    break;
                }
                if(j == i-1){
                    anscount++;
                    // printf("yes\n");
                }
            }
        }
    }
    printf("%d\n",anscount);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",pass);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^