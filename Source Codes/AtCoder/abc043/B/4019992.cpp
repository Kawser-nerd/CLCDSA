#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 2e3+55;
int main()
{
    string s;
    cin>>s;
    char ans[100];
    int len = 0;
    for(int i = 0 ;i <s.size(); ++i)
    {
        if(s[i] == 'B')
        {
            if(len) len--;
        }
        else ans[++len] = s[i];

    }
    for(int i=1;i<=len;++i)
        cout<<ans[i];
    return 0;
}