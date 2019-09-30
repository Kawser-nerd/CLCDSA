#include<stdio.h>
#include<string.h>
#define LEN 50
int Mystrcmp(char *a,char *b,int n)
{
    for(int i=0;b[i];i++)
        if(a[n+i]!='?'&&a[n+i]!=b[i])
            return 0;
    return 1;
}
int main()
{
    char a[LEN],b[LEN];
    gets(a);
    gets(b);
    int lenb = strlen(b);
    int lena = strlen(a);
    int i;
    for(i=lena-lenb;i>=0;i--)
        if(Mystrcmp(a,b,i))
            break;
    if(i>=0)
    {
        for(int j = 0;a[j];j++)
            if(a[j]=='?')
                a[j] = 'a';
        for(int j = 0;b[j];j++)
            a[i++] = b[j];
        puts(a);
    }
    else printf("UNRESTORABLE\n");
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(a);
     ^
/tmp/ccYUHyCh.o: In function `main':
Main.c:(.text.startup+0x25): warning: the `gets' function is dangerous and should not be used.