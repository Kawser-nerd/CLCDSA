#include <cstdio>
using namespace std;
typedef long long ll;
ll n, cnt = 0;

void dfs(int k, ll last){
    if(k > 9 || last > n) return;
    ll tmp = last;
    int a = 0, b = 0, c = 0;
    while(tmp > 0){
        int s = tmp%10;
        tmp/=10;
        if(s == 3) a = 1;
        if(s == 5) b = 1;
        if(s == 7) c = 1;
        if(a && b && c) break;
    }
    if(last <= n && a && b && c) cnt++;
    dfs(k+1, last*10+3);
    dfs(k+1, last*10+5);
    dfs(k+1, last*10+7);
}

int main()
{
    scanf("%lld", &n);
    dfs(0, 0);
    printf("%lld\n", cnt);
    return 0;
}