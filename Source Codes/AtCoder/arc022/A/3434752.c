#include <stdio.h>
#include <string.h>
int main(void){
    char s[120];
    int count=0;
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++){
        if (count==0){
            if (s[i]=='I' || s[i]=='i'){
                count=1;
            }
        } else if (count==1){
            if (s[i]=='C' || s[i]=='c'){
                count=2;
            }
        } else if (count==2){
            if (s[i]=='T' || s[i]=='t'){
                count=3;
            }
        }
    }
    if (count==3){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^