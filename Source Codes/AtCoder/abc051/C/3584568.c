#include <stdio.h>
#include <stdlib.h>
void print_road1(int a,int b)
{
    int i;
    for(i=1;i<=b;i++)
    {
        printf("U");
    }
    for(i=1;i<=a;i++)
    {
        printf("R");
    }
}

void print_road2(int a,int b)
{
    int i;
    for(i=b;i>=1;i--)
    {
        printf("D");
    }
    for(i=a;i>=1;i--)
    {
        printf("L");
    }
}

int main()
{
    int sx,sy,tx,ty,x,y;
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    x=tx-sx;
    y=ty-sy;
    print_road1(x,y);
    print_road2(x,y);
    printf("L");
    x=x+1;
    y=y+1;
    print_road1(x,y);
    printf("D");
    printf("R");
    print_road2(x,y);
    printf("U");


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
     ^