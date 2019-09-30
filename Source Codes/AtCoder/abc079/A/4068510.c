#include <stdio.h>
int main(void){
    char n[10];
    gets(n);
    if((n[0]==n[1] && n[1]==n[2]) || (n[1]==n[2] && n[2]==n[3]))
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(n);
     ^
/tmp/ccqWR9y0.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.