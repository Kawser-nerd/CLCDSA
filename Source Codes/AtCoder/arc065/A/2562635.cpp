#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include <string.h>
#include <math.h>
#include<map>
#include<string.h>
#define ll long long
using namespace std;
char mode[4][15]={"dream","dreamer","erase","eraser"};
int modelen[4]={5,7,5,6};
char str[100050];
bool dp[100050];
int main()
{
    int i,j,k,flag;
    scanf(" %s",str);
    int l=strlen(str);
    dp[0]=1;
    for(i=0;i<l;i++)
    {
        if(dp[i])
        {
            for(j=0;j<4;j++)
            {
                flag=0;
                for(k=0;k<modelen[j];k++)
                {
                    if(str[i+k]!=mode[j][k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    dp[i+modelen[j]]=1;
                }
            }
        }
    }
    if(dp[l])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}