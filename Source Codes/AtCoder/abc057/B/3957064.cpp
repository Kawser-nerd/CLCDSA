#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<pair<int32_t, int32_t>> va(N);
    vector<pair<int32_t, int32_t>> vc(M);
    for(auto& e : va)
        cin >> e.first >> e.second;
    for(auto& e : vc)
        cin >> e.first >> e.second;

    for(auto& ea : va)
    {
        int32_t dmin = 400000000;
        int ans = 0;
        for(int i = M - 1; i >= 0; --i)
        {
            int32_t d = abs(ea.first - vc[i].first) + abs(ea.second - vc[i].second);
            if(dmin >= d)
            {
                dmin = d;
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}