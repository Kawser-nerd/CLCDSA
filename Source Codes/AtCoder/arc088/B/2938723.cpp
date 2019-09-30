#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<time.h>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
const int maxn=1e5+100;
char a[maxn];
int main()
{
    scanf("%s",a);
    int len=strlen(a),ans=len;
    for(int i=1;i<len;i++)
        if(a[i-1]!=a[i])
            ans=min(ans,max(i,len-i));
    printf("%d\n",ans);
    return 0;
}