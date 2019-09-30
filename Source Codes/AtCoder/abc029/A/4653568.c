#include<stdio.h>
#include<string.h>
int main(){
    char W[100];
    scanf("%s",W);
    strcat(W,"s");
    printf("%s\n",W);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",W);
     ^