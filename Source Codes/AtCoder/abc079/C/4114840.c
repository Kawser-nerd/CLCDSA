#include<stdio.h>
int main(void)
{
    int b;
    int a[4];
    char c[4];
    gets(c);
    a[0]=c[0]-'0';
    a[1]=c[1]-'0';
    a[2]=c[2]-'0';
    a[3]=c[3]-'0';
    if(a[0]+a[1]+a[2]+a[3]==7)
        printf("%d+%d+%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]+a[1]+a[2]-a[3]==7)
        printf("%d+%d+%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]+a[1]-a[2]+a[3]==7)
        printf("%d+%d-%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]+a[1]-a[2]-a[3]==7)
        printf("%d+%d-%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]-a[1]+a[2]+a[3]==7)
        printf("%d-%d+%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]-a[1]+a[2]-a[3]==7)
        printf("%d-%d+%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]-a[1]-a[2]+a[3]==7)
        printf("%d-%d-%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
    else if(a[0]-a[1]-a[2]-a[3]==7)
        printf("%d-%d-%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(c);
     ^
./Main.c:13:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d+%d+%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
                ^
./Main.c:15:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d+%d+%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
                ^
./Main.c:17:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d+%d-%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
                ^
./Main.c:19:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d+%d-%d-%d=7\n",a[0],a[1],a[2],a[3],a[4]);
                ^
./Main.c:21:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d-%d+%d+%d=7\n",a[0],a[1],a[2],a[3],a[4]);
                ^
./Main.c:23:16: warning: too many arguments for format [-Wformat-extra-args]
         printf("%d...