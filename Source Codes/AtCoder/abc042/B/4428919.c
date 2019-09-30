#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, l, i, j;
    char s[100][101], ans[100000] , tmp[101];

    scanf("%d%d", &n, &l);
    for(i=0;i<n;i++){
        scanf("%s", s[i]);
    }

    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(strcmp(s[i], s[i+1])>0){
                strcpy(tmp, s[i]);
                strcpy(s[i], s[i+1]);
                strcpy(s[i+1], tmp);
            }
        }
    }
    
    for(i=0;i<n;i++){
        printf("%s", s[i]);
    }
    printf("\n");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &l);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);
         ^