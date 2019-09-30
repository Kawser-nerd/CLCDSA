#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[101];
    int n[4],i,j;
    scanf("%s",s);
    for(i=0;i<4;i++){
        scanf("%d",&n[i]);
    }
    for(i=0;i<strlen(s);i++){
        for(j=0;j<4;j++){
            if(i==n[j]){
                printf("\"");
            }
        }
        printf("%c",s[i]);
    }
    if(i==n[3]){
        printf("\"");
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n[i]);
         ^