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
    int N;
    cin >> N;

    set<int> k;
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int ai;
        cin >> ai;
        auto r = k.insert(ai);
        if(!r.second)
            ans++;
    }
    cout << ans << endl;
    return 0;
}