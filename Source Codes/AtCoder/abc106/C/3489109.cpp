#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int main()
{
    string s;ll m;
    cin>>s;
    cin>>m;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='1')
        {

            printf("%d\n",s[i]-'0');
            return 0;
        }
        if(i+1==m)
        {
            printf("%d\n",s[i]-'0');
            return 0;
        }
    }
    printf("1\n");
    return 0;
}