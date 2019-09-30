#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){
    char n[4];
    scanf("%s",n);
    int i;
    for(i=0;i<3;i++){
        if(n[i]=='1'||n[i]=='9'){
            if(n[i]=='1') n[i]='9';
            else n[i]='1';
        }
    }
    printf("%s",n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",n);
     ^