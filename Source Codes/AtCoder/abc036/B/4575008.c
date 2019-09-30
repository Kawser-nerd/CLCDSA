#include <stdio.h>

int main()
{   int n;
    scanf("%d",&n);
    char s[n][n+1];
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            printf("%c",s[j][i]);
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^