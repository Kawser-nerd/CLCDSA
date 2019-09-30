#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c;
    
    scanf("%d %d %d%*c", &a, &b, &c);
    
    if(a + b == c && a - b == c){
        printf("?\n");
    }else if(a + b == c){
        printf("+\n");
    }else if(a - b == c){
        printf("-\n");
    }else{
        printf("!\n");
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d%*c", &a, &b, &c);
     ^