#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long bound=1000000000LL;
vector <long long> arr;
void dfs(long long cur,bool f3,bool f5,bool f7)
{
    if(f3&&f5&&f7)
        arr.push_back(cur);
    if(cur>bound)
        return ;
    dfs(cur*10+3,true,f5,f7);
    dfs(cur*10+5,f3,true,f7);
    dfs(cur*10+7,f3,f5,true);
    return ;
}

void init()
{
    arr.clear();
    dfs(0,false,false,false);
    sort(arr.begin(),arr.end());
}

int main()
{
    init();
    long long x;
    while(scanf("%lld",&x)!=EOF)
    {
        int tmp=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        printf("%d\n",tmp);
    }
    return 0;
}