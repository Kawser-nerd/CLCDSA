#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#define N 200005
using namespace std;
char str[N],mm[N];
int dp[N];
int route[N];
int a[30];
int main(void)
{
    scanf("%s",str + 1);
    int l = strlen(str+1);
    //memset(nex,-1,sizeof(nex));
    memset(route,-1,sizeof(route));
    memset(dp,0x3f,sizeof(dp));
    memset(a,-1,sizeof(a));
    int id = 0;
    dp[l+1] = 1;
    route[l+1] = l + 1;
    mm[l+1] = 0;
    for(int i = l+2;i < N;i++)
        dp[i] = 0;
    for(int i = 0; i < 26; i++)
        a[i] = l+1;
    for(int i = l; i >= 1; i--)
    {
        a[str[i]-'a'] = i;
        for(int j = 0; j < 26; j++)
        {
            if(dp[i] > dp[a[j] + 1] + 1)
            {
                mm[i] = j;
                //printf("%d\n",j);
                dp[i] = dp[a[j] + 1]+1;
                route[i] = a[j] + 1;
            }
        }
    }
    //printf("%d\n",dp[1]);
    int f = 1;
    while(f<l+1)
    {
        printf("%c",mm[f] + 'a');
        f = route[f];
    }
    return 0;
}