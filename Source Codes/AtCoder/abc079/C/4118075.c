#include<stdio.h>
int main()
{
    char A[5];
    int a,b,c,d;
    scanf("%s",A);
    a=A[0]-48;
    b=A[1]-48;
    c=A[2]-48;
    d=A[3]-48;
    if(a+b+c+d==7)
        printf("%d+%d+%d+%d=7",a,b,c,d);
    else if(a+b+c-d==7)
        printf("%d+%d+%d-%d=7",a,b,c,d);
    else if(a+b-c+d==7)
        printf("%d+%d-%d+%d=7",a,b,c,d);
    else if(a+b-c-d==7)
        printf("%d+%d-%d-%d=7",a,b,c,d);
    else if(a-b+c+d==7)
        printf("%d-%d+%d+%d=7",a,b,c,d);
    else if(a-b+c-d==7)
        printf("%d-%d+%d-%d=7",a,b,c,d);
    else if(a-b-c+d==7)
        printf("%d-%d-%d+%d=7",a,b,c,d);
    else
        printf("%d-%d-%d-%d=7",a,b,c,d);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",A);
     ^