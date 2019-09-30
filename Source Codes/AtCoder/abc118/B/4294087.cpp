#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;

int main()
{
    int n, m, k, a, ans = 0;
    
    cin >> n >> m;
    
    int tmp = n;
    while(tmp--)
    {
        cin >> k;
        while(k--)
        {
            cin >> a;
            ++mp[a];
        }
    }
    
    for(int i = 1; i <= m; ++i) 
        if(mp[i] == n) ++ans;
    
    cout << ans;
    
    return 0;
}