#include <stdio.h>
#include <string.h>
 
char str [100005],dr[10]="dream", er[10]="erase";
//dreamer????er?erase?????????i+3?? 
int main()
{
    gets(str);
    
        int len = strlen (str);
        int i,ok=1;
        for (i=0;i<len;i++)//dreameraser
        {
            if (str[i]=='d')
            {
                int j;
                for (j=i;j<=i+4;j++)
                {
                    if (j>=len||dr[j-i]!=str[j])
                    {
                        ok=0;
                        break;
                    }
                }
                if (j==i+5)//?dream
                {
                    i=j-1;
                    if (str[j]=='e'&&str[j+1]=='r'&&str[j+2]!='a')
                    {
                        i=j+1;
                    }
                }
            }
            else if (str[i]=='e')
            {
                int j;
                for (j=i;j<=i+4;j++)
                {
                    if (j>=len||er[j-i]!=str[j])
                    {
                        ok=0;
                        break;
                    }
                }
                if (j==i+5) //?erase
                {
                    i=j-1;
                    if (str[j]=='r') i=j;
                    else i=j-1;
                }
            }
            else ok=0;
            if (ok==0) break;
        }
        if (ok==1)
            printf("YES");
        else
            printf("NO");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(str);
     ^
/tmp/cc5uppa2.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.