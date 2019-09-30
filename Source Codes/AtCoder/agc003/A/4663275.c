#include <stdio.h>
#include <string.h>

int main(void){
    int ec=0,wc=0,nc=0,sc=0;
    int flagew=0,flagns=0;
    char s[1000];
    scanf("%s",s);
    for(int i=0;i<=strlen(s);i++){
        if(s[i] == 'E')ec++;
        else if(s[i] == 'W')wc++;
        else if(s[i] == 'N')nc++;
        else if(s[i] == 'S')sc++;
    }
    if(ec == wc){
        flagew = 1;
    }else if(ec != 0 && wc != 0){
        flagew = 1;
    }
    if(nc == sc){
        flagns = 1;
    }else if(nc != 0 && sc != 0){
        flagns = 1;
    }
    if(flagns && flagew){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^