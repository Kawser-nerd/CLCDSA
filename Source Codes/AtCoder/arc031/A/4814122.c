#include <stdio.h>
#include <string.h>
int main(void){
    char s[101];
    int i,n;
    scanf("%s",&s);
    n=strlen(s);
    for(i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^