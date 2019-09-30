#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 55
int fun(char temp[N],char S[],char T[],int len_S,int len_T,int *pos)
{
    int i=0,flag=0,counter=0,j;
        while(i<=len_S-len_T)
        {
            strncpy(temp,S+len_S-len_T-i,len_T);
            *pos=len_S-len_T-i;
            for(j=0;j<len_T;j++)
            {
                if(temp[j]==T[j]||temp[j]=='?')
                        counter++;
            }
            if(counter==len_T)
                {
                    flag++;
                    break;
                }
            counter=0;
            i++;
        }
        if(flag)
            return 1;
        else
            return 0;

}

int main()
{
    char S[N],T[N];
    char temp[N];
    int pos=0,i;
    gets(S);
    gets(T);
    int len_S,len_T;
    len_S=strlen(S);
    len_T=strlen(T);
    if(len_S<len_T)
        printf("UNRESTORABLE");
    else
    {
            if(fun(temp,S,T,len_S,len_T,&pos))
            {
                strncpy(S+pos,T,len_T);
                for(i=0;i<len_S;i++)
                {
                    if(S[i]=='?')
                        S[i]='a';
                }
                printf("%s",S);
            }
            else
            {
 printf("UNRESTORABLE");
            }

    }


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(S);
     ^
/tmp/cclYAyhv.o: In function `main':
Main.c:(.text.startup+0x3b): warning: the `gets' function is dangerous and should not be used.