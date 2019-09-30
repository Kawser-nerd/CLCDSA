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
    int N, S, T;
    cin >> N >> S >> T;

    int w = 0;
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int ai;
        cin >> ai;
        w += ai;
        if(S <= w && w <= T)
            ans++;
    }
    cout << ans << endl;
    return 0;
}