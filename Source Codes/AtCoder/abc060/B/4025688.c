#include<stdio.h>
int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<100;i++)
    {
        if(c==(a*i)%b)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^