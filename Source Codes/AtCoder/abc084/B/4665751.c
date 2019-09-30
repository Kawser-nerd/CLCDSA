#include <stdio.h>
#include <ctype.h>
int main(void){
    int a,b,i;
    char s[12];
    scanf("%d%d%s",&a,&b,s);
    for(i=0;i<a;i++){
        if(isdigit(s[i])==0){
            printf("No\n");
            return 0;
        }
    }
    if(s[a]!='-'){
        printf("No\n");
        return 0;
    }
    for(i=a+1;i<a+1+b;i++){
        if(isdigit(s[i])==0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%s",&a,&b,s);
     ^