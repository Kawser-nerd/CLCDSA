#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    int sign = 1;
    for(auto& e : a)
    {
        ans += sign * e;
        sign *= -1;
    }

    cout << ans << endl;

    return 0;
}