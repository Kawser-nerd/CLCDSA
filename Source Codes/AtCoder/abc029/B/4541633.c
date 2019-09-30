#include <stdio.h>
int main(void){
    // Your code here!
    char s[11];
    int cnt=0;
    for(int i=0;i<12;i++){
        scanf("%s",s);
        for(int j=0;s[j]!='\0';j++){
            if(s[j]=='r'){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s);
         ^