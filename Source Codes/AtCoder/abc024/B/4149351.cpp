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
    int N, T;
    cin >> N >> T;

    vector<int> v(N, 0);
    for(auto& e : v)
        cin >> e;
    
    uint64_t ans = 0;
    if(1 < N)
    {
        for(int i = 0; i < N - 1; ++i)
        {
            int a0 = v[i];
            int a1 = v[i + 1];
            if(a0 != a1)
            {
                if(a1 - a0 < T)
                    ans += a1 - a0;
                else
                    ans += T;
            }
        }
    }
    cout << ans + T << endl;
    
    return 0;
}