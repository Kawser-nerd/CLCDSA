#include <iostream>
#include<cstring>

using namespace std;
int len,ans = 0 ,res=0;
char d[3]={'3','5','7'},x[11];
    int  num;
bool isValid(char a[])
{
    int cnt[11]={0};
    for(int i=0;i<strlen(a);i++)
    {
        cnt[a[i]-'0']++;
    }

    if(cnt[3] >= 1 && cnt[5] >= 1 && cnt[7] >= 1 &&  cnt[3] + cnt[5] + cnt[7] == strlen(a))
    {
        if(atoi(a) <= num)
        return true;
    }
    return false;
}

void dfs(int pos ,int len ,char  a[] )
{
    if(pos == len )
    {
        a[len]='\0';
        if(isValid(a))
        {
            res++;
        }
        return ;
    }
        a[pos] = '3';
        dfs(pos+1,len,a);

        a[pos] = '5';
        dfs(pos+1,len,a);

        a[pos] = '7';
        dfs(pos+1,len,a);
}
int main()
{

    int i,j,k;
    char str[11];
     scanf("%s",&str);
    num = atoi(str);
    len = strlen(str);

    for(i = 3;i<=len;i++)
        dfs(0,i,x);
    cout<<res;

    return 0;
} ./Main.cpp:49:17: warning: format specifies type 'char *' but the argument has type 'char (*)[11]' [-Wformat]
     scanf("%s",&str);
            ~~  ^~~~
1 warning generated.