#include<stdio.h>
int at(int x, int y);
int main(void)
{

        int a,b,c;

        scanf("%d%d",&a,&b);
        if((1<=a) && (a<=b) && (b<=20))
                c = at(a, b);
        else
                printf("?????????????\n");
        printf("%d\n",c);
        return 0;
}

int at(int x, int y){

        int g;

        if(y%x==0)
                g = x + y;
        else
                g = y - x;
        return g;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^