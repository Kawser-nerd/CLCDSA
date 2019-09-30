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
    int N, a, b, K;
    cin >> N >> a >> b >> K;

    string ans = "YES";
    set<int> s;
    s.insert(a);
    s.insert(b);
    for(int i = 0; i < K; ++i)
    {
        int pi;
        cin >> pi;
        auto r = s.insert(pi);
        if(!r.second)
            ans = "NO";
    }

    cout << ans << endl;
    return 0;
}