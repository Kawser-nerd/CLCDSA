#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51],skn[51],t[51];
    int lens,lent,i,j,k,flag;
    scanf("%s",skn);
    scanf(" %s",t);
    lens=strlen(skn);
    lent=strlen(t);
    if (lent>lens) printf("UNRESTORABLE");
    else
    {
        for (i=0;i<=lens-lent;i++)
        {
            for (flag=1,j=lens-1-i,k=lent-1;k>=0;j--,k--)
            {
                if (skn[j]=='?') continue;
                if (skn[j]!=t[k])
                {
                    flag=0;
                    break;
                }
            }
            if (flag==1)
            {
                strcpy(s,skn);
                for (j=lens-1-i,k=lent-1;k>=0;j--,k--)
                    s[j]=t[k];
                for (j=0;j<lens;j++)
                    if (s[j]=='?') s[j]='a';
                puts(s);
                exit(0);
            }
        }
        printf("UNRESTORABLE");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",skn);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %s",t);
     ^