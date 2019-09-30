#include <stdio.h>

int main(void){
    int n, i, j;
    scanf("%d",&n);
    char p[100000];
    
    int tak=0, aok=0;
    for(i=0; i<n*n; i++){
        p[i] = getchar();
        if(p[i] == '\n')p[i]=getchar();
        if(p[i] == 'R')tak++;
        if(p[i] == 'B')aok++;
    }
    
    if(tak > aok)printf("TAKAHASHI\n");
    if(tak == aok)printf("DRAW\n");
    if(tak < aok)printf("AOKI\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^