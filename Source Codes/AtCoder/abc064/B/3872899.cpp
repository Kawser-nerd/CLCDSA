#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < N - 1; ++i)
        ans += v[i] - v[i + 1];

    cout << ans << endl;
    return 0;
}