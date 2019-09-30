#include <stdio.h>

int main(){
    char s[50];
    scanf("%s",&s);
    for (int i=0;i<50;i++){
        if (s[i+1]=='\0'){
            if (s[i]=='T'){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            break;
        }        
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^