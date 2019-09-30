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

set<pair<pair<int, int>, int>> m;

int A, B, C;

int main()
{
    cin >> A >> B >> C;

    int ans = 0;
    while (1)
    {
        if (A % 2 || B % 2 || C % 2)
        {
            break;
        }
        auto ABC = make_pair(make_pair(A, B), C);
        if (m.find(ABC) != m.end())
        {
            ans = -1;
            break;
        }
        ans++;
        m.insert(ABC);

        int a = B / 2 + C / 2;
        int b = A / 2 + C / 2;
        int c = B / 2 + A / 2;
        A = a;
        B = b;
        c = C;
    }

    cout << ans << endl;

    return 0;
}