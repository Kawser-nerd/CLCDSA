#include <stdio.h>
int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && b>c) printf("1\n2\n3\n");
    else if(a>c && c>b) printf("1\n3\n2\n");
    else if(b>c && c>a) printf("3\n1\n2\n");
    else if(b>a && a>c) printf("2\n1\n3\n");
    else if(c>a && a>b) printf("2\n3\n1\n");
    else if(c>b && b>a) printf("3\n2\n1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^