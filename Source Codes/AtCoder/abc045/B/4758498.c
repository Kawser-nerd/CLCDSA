#include <stdio.h>
#include <string.h>
int main(void){
    int i=0,f[3]={0};
    char s[3][101];
    scanf("%s%s%s",s[0],s[1],s[2]);
    while(1){
        f[i]++;
        if(strlen(s[0])<f[0]){
            printf("A\n");
            return 0;
        }
        else if(strlen(s[1])<f[1]){
            printf("B\n");
            return 0;
        }
        else if(strlen(s[2])<f[2]){
            printf("C\n");
            return 0;
        }
        i=s[i][f[i]-1]-'a';
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",s[0],s[1],s[2]);
     ^