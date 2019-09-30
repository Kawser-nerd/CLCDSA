#include <stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    char s[n][n];
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(j=0;j<n;j++){
    for(i=n-1;i>=0;i--)printf("%c",s[i][j]);
        printf("\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++)scanf("%s",s[i]);
                     ^