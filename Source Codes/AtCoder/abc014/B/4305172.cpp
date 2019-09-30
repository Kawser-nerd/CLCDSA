#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int n, X;
    cin >> n >> X;
    vector<int> vp(n);
    for(auto& e : vp)
        cin >> e;
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int b = 1 << i;
        if(X & b)
            ans += vp[i];
    }

    cout << ans << endl;
    return 0;
}