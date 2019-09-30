#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<std::pair<int, bool> > v(N);
    for(auto& e : v)
    {
        int ai;
        cin >> ai;
        e = make_pair(ai, false);
    }

    int next = 0;
    int ans = 0;
    while(1)
    {
        if(v[next].second)
        {
            ans = -1;
            break;
        }
        if(1 == next)
            break;
        v[next].second = true;
        next = v[next].first - 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}