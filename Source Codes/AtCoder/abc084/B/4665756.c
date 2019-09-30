#include <stdio.h>
int main(void){
    int a,b,i;
    char s[12];
    scanf("%d%d%s",&a,&b,s);
    for(i=0;i<a+b+1;i++){
        if(i!=a){
            if(isdigit(s[i])==0){
                printf("No\n");
                return 0;
            }
        }
        else{
            if(s[i]!='-'){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:16: warning: implicit declaration of function ‘isdigit’ [-Wimplicit-function-declaration]
             if(isdigit(s[i])==0){
                ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%s",&a,&b,s);
     ^