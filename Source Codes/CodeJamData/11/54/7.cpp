/**********************************************************************
Author: hanshuai
Created Time:  2011/6/11 22:19:40
File Name: d.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 150;
typedef long long LL;
char s[maxn];
vector<int> vec;
LL mc, ans;
bool isPS(LL v){
    LL x = (LL)sqrt((double)v);
    for(int i = -5; i <= 5; i ++){
        if((x+i)*(x+i) == v) return true;
    }
    return false;
}
void solve(int th){
    if(th == (int)vec.size()){
        if(isPS(mc)){
            ans = mc;
        }
        return;
    }
    solve(th+1);
    mc += 1LL<<vec[th];
    solve(th+1);
    mc -= 1LL<<vec[th];
}
int main() {
    freopen("d.out", "w", stdout);
    int test, cas = 0;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d: ", ++cas);
        scanf("%s", s);
        int n = strlen(s);
        vec.clear();
        mc = 0;
        ans = -1;
        for(int i = 0; i < n; i ++){
            int th = n-1-i;
            if(s[i] == '1') mc += 1LL<<th;
            else if(s[i] == '?') vec.push_back(th);
        }
        solve(0);
        assert(ans != -1);
        for(int i = n-1; i >= 0; i--){
            printf("%d", (int)((ans>>i)&1));
        }
        printf("\n");
    }
    return 0;
}

