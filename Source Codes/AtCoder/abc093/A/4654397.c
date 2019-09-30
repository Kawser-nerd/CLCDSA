#include <stdio.h>

int main(void){
    char s[3];
    int sc[3] = {0};
    int flag = 0;
    scanf("%s",s);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[i] == 'a'+j)sc[j]++;
        }
    }
    for(int i=0;i<3;i++){
        if(sc[i] > 1){
            flag = 1;
        }
    }
    if(flag)printf("No\n");
    else printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^