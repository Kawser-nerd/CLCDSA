#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    char s[n][n+1];
    int i,j;
    for(i = 0;i<n;i++){
        scanf("%s",s[i]);
    }
    printf("\n");
    for(i = 0;i<n;i++){
        for(j = n-1;j>=0;j--){
            printf("%c",s[j][i]);
            if(j == 0){
                printf("\n");
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^