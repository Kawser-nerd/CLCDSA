#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

long long N, A, B, C, D;

int main()
{
    string ans = "NO";
    cin >> N >> A >> B >> C >> D;
    for (int i = 0; i < N - 1; i++)
    {
        if(C * (N - 1 - i) - D * i <= B - A && B - A <= -C * i + (N - 1 - i) * D)
        {
            ans = "YES";
        }
    }
    cout << ans << endl;

    return 0;
}