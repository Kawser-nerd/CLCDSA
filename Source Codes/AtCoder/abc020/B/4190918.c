#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char a[8],b[4];
    int num;

    scanf("%s %s",&a,&b);

    num = atoi(strcat(a,b));
    printf("%d\n",num*2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[8]’ [-Wformat=]
     scanf("%s %s",&a,&b);
           ^
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[4]’ [-Wformat=]
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s",&a,&b);
     ^