#include <stdio.h>
int f(int x){
    int n = 1;
    for(int i = 2;i <= x;i++)
        n += i;
    return n;
}
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    int x = b-a;
    printf("%d",f(x)-b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^