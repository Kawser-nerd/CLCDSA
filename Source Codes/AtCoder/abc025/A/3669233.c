//
#include <stdio.h>
int main(void){
    // Your code here!
    char s[5],a[1];
    int n;
    scanf("%s\n%d",&s,&n);
    n--; //a=s[0]s[0]???????????
    a[0]=s[n/5]; //????????
    a[1]=s[n%5]; //????????
    printf("%s\n",a);
} ./Main.c: In function ‘main’:
./Main.c:7:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
     scanf("%s\n%d",&s,&n);
           ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s\n%d",&s,&n);
     ^