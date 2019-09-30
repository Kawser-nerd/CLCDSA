#include<stdio.h>
int main()
{
        int a, b, c;
        int x,y;
        scanf("%d %d %d %d %d", &a,&b,&c,&x,&y);
        if(2*c>= a+b){
            printf("%d",x*a+y*b);
        }
        else {
            if(b<a){
                int b0 =a;
                a =b;
                b = b0;
                b0 = x;
                x = y;
                y = b0;
            }
            if(2*c<a){
                if(y<x){
                    printf("%d",x*2*c);
                }
                else{
                    printf("%d",y*2*c);

                }
            }
            else if(2*c<b){
                if(y<x){
                    printf("%d",y*2*c+(x-y)*a);
                }
                else{
                    printf("%d",y*2*c);
                }
            }
            else{
                if(y<x){
                    printf("%d",y*2*c+(x-y)*a);
                }
                else{
                    printf("%d",x*2*c+(y-x)*b);
                }
            }

        }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d %d %d", &a,&b,&c,&x,&y);
         ^