#include<stdio.h>
#include<math.h>
//using namespace std;
int main()
{
    int x,a,b;
     scanf("%d%d%d",&x,&a,&b);
    if(abs(a-x)<abs(b-x))
        printf("A");
    else
        printf("B");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:8: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if(abs(a-x)<abs(b-x))
        ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d%d%d",&x,&a,&b);
      ^