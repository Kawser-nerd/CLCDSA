#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    if (abs(a)<abs(b)){
        printf("Ant\n");
    } else if (abs(a)==abs(b)){
        printf("Draw\n");
    } else {
        printf("Bug\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^