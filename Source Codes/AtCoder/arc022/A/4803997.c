#include <stdio.h>
#include <string.h>
int main(void){
    char s[101];
    int i,j,k;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='i' || s[i]=='I'){
            for(j=i;j<strlen(s);j++){
                if(s[j]=='c' || s[j]=='C'){
                    for(k=j;k<strlen(s);k++){
                        if(s[k]=='t' || s[k]=='T'){
                            printf("YES\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^