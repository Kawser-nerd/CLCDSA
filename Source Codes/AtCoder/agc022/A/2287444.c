#include <stdio.h>
#include <string.h>
char s[30];
int i,j,len,vv,k,v[100];
int main()
{
    scanf("%s",s);
    len=strlen(s);
    if (len<26)
    {
        for (i=0;i<=30;i++)
            v[i]=0;
        for (i=0;i<=len-1;i++)
            v[s[i]-'a']=1;
        for (i=0;i<=25;i++)
        if (v[i]==0)
        break;
        printf("%s",s);
        printf("%c",i+'a');
    } else
    {
        vv=0;
        for (j=0;j<=len-2;j++)
        if (s[j]-s[j+1]!=1) {vv=1; break;}
        if (vv==0) {printf("-1");return(0);}
        i=0;
        for (j=0;j<=25;j++)
            v[j]=0;
        while (i<=len-1)
        {
         for (j=i+1;j<=len-1;j++)
            {
                vv=0;
             for (k=j+1;k<=len-1;k++)
             {
              if (s[k]>s[j])
                {
                 vv=1;
                 break;
                }
              }
              if (vv==1) break;
            }
            if (vv) {printf("%c",s[i]);v[s[i]-'a']=1;} else
            {
                for (j=0;j<=25;j++)
                if (v[j]==0&&j+'a'>s[i])
                {
                    printf("%c",j+'a');
                    break;
                }
                break;
            }
            i++;
        }
    }
    return(0);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^