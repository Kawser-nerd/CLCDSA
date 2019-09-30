#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    int i,l,c=0,d=0;
    scanf("%s",str);
    l=strlen(str);
    for(i=2;i<l;i++)
    {
        if(str[i]=='C')
        {
            c++;
        }
        if(str[i]>='a'&&str[i]<='z')
        {
            d++;
        }
    }
    if(str[1]>='a'&&str[1]<='z')
    {
        d=d+1;
    }
    if(str[l-1]=='C')
    {
        c=c-1;
    }
    if(str[0]=='A'&&c==1&&d==l-2)
    {
        printf("AC\n");
    }
    else
    {
        printf("WA\n");
    }

    return 0;
}