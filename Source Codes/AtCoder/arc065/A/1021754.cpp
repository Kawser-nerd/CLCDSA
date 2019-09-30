#include <stdio.h>
#include <string.h>

char str [100005];
char dr[10]="dream";
char er[10]="erase";

int main()
{
    while (scanf("%s",&str)!=EOF)
    {
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
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
} ./Main.cpp:10:23: warning: format specifies type 'char *' but the argument has type 'char (*)[100005]' [-Wformat]
    while (scanf("%s",&str)!=EOF)
                  ~~  ^~~~
1 warning generated.