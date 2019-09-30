#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, c;
    scanf("%d%d%d%d", &a, &b, &c);
    if(a+b < c){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:11: warning: format ‘%d’ expects a matching ‘int *’ argument [-Wformat=]
     scanf("%d%d%d%d", &a, &b, &c);
           ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &a, &b, &c);
     ^