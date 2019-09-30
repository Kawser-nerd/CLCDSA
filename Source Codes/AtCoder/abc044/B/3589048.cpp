#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num[30];
int main()
{
    char s[103];
    scanf("%s",s);
    int l = strlen(s);
    for(int i=0;i<l;i++)
    {
        num[ s[i]-'a' ]++;
    }
    bool flag = 0;
    for(int i=0;i<26;i++)
        if(num[i]&1)
    {
        flag = 1;
        break;
    }
    if(flag)
        puts("No");
    else puts("Yes");
    return 0;
}