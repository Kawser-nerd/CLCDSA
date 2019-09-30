#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < K; ++i)
    {
        ans += v[N - 1 - i];
    }
    cout << ans << endl;
    return 0;
}