#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
if(a>b)
    return a;
else
    return b;
}
int main()
{
char s[10];
int i;
int j;
int r;
int len;
int result=0;
gets(s);
len=strlen(s);
int posible;
for(i=0;i<len;i++){
    for(j=i;j<len;j++){
        posible=1;
        for(r=i;r<=j;r++){
            if(s[r]!='A' && s[r]!='T'&&s[r]!='C'&&s[r]!='G')
            posible=0;
        }
    if(posible)
        result=max(result,j-i+1);
    }

}

printf("%d",result);
} ./Main.c: In function ‘main’:
./Main.c:17:1: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 gets(s);
 ^
./Main.c:18:5: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 len=strlen(s);
     ^
./Main.c:18:5: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:18:5: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
/tmp/ccGg7j2t.o: In function `main':
Main.c:(.text.startup+0x21): warning: the `gets' function is dangerous and should not be used.