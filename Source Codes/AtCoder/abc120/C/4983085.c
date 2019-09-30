#include<stdio.h>
int main(void){
    char S[100000];
    int r,b;
    scanf("%s",S);
    for(int i=0;S[i]!='\0';i++){
        if (S[i]=='1') {
            b++;
        }
        else{
            r++;
        }
    }
    if(r<b){
        printf("%d\n",r*2);
    }
    else{
        printf("%d\n",b*2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^