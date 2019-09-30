#include <stdio.h>

int main(int argc, char *argv[])
{
    char buf[1000032];
    int i, n, total = 0;
    fgets(buf, sizeof(buf), stdin);

    n = buf[0] - '0';
    for ( i = 1; buf[i] != '\n'; i++ ){
        if ( buf[i] == '+' ){
            if ( n != 0 ){
                total++;
            }
            n = -1;
        } else if ( buf[i] == '*' ){
            ;
        } else {
            if ( n != 0 ){
                n = buf[i] - '0';
            }
        }
    }
    if ( n > 0 ){
        total++;
    }
    printf("%d\n", total);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf, sizeof(buf), stdin);
     ^