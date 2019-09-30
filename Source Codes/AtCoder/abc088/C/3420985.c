#include<stdio.h>

int main(){
    int a,b,c,d,e,f,g,h,i;
    scanf("%d %d %d",&a,&b,&c);
    scanf("%d %d %d",&d,&e,&f);
    scanf("%d %d %d",&g,&h,&i);
    int x = a+e+i;
    int y = b+f+g;
    int z = c+d+h;
    if(x==y && y==z) printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&c);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&d,&e,&f);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&g,&h,&i);
     ^