#include<stdio.h>
int main()
{
    int a, b, target;

    // read line
    scanf("%d %d", &a, &b);
    if ( b > 9 && b < 100 ) {
        target = a*100 + b;
    }else if ( b < 10 ) {
        target = (a*10) + b;
    } else {
        target = (a*1000) + b;
    }
    for (int i=1;i<316;i++){
        if ( target == i*i ){
            printf("Yes\n");
             return 0;
        }
    }
    printf("No\n"); 
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^