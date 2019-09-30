#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char S1[50],T[50];
    int i,j,o;
    int lenS1,lenT;
    int k,p,w=0;
    gets(S1);
    gets(T);
    lenS1=strlen(S1);
    lenT=strlen(T);
    for (i=0; i<=lenS1-lenT; i++)
    {
        k=0;
        p=1;
        for (j=i; j<i+lenT; j++)
        {
            if ((S1[j]!=T[k++])&&(S1[j]!='?'))
            {
                p=0;
            }
        }
        if (p==1)
        {
            o=i;
            w=1;
        }
    }
    if (w==1)
    {
        k=0;
        for (j=o; j<o+lenT; j++)
        {
            S1[j]=T[k++];
        }
        for (i=0; i<lenS1; i++)
        {
            if (S1[i]=='?')
            {
                S1[i]='a';
            }
        }
        puts(S1);
    }
    else
    {
        printf("UNRESTORABLE");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(S1);
     ^
/tmp/ccreXLFw.o: In function `main':
Main.c:(.text.startup+0x35): warning: the `gets' function is dangerous and should not be used.