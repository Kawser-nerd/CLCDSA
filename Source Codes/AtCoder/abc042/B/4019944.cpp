#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 2e3+55;
string s[MAXN];
int main()
{
    int n,l;
    cin>>n>>l;
    for(int i = 0; i < n; ++i)
        cin>>s[i];
    sort(s,s+n);
    for(int i = 0; i < n;++i)
        cout<<s[i];
    return 0;
}