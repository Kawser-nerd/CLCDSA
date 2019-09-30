#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int X, i, t = 0;
 
    scanf("%d", &X);
 
    for ( i = 1; i <= X; i++ ){
        t += i;
        if ( t >= X ){
            break;
        }
    }
    printf("%d\n", i);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &X);
     ^