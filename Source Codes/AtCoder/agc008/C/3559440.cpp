#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    long long ai, ao, at, aj, al, as, az;

    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    long long ans, ans1, ans2;

    ans1 = 2 * (ai / 2) + ao + 2 * (aj / 2) + 2 * (al / 2) + 3 * (ai % 2) * (aj % 2) * (al % 2);
    ans2 = 0;

    if (ai > 0 && aj > 0 && al > 0)
    {
        ans2 = 2 * ((ai-1) / 2) + ao + 2 * ((aj-1) / 2) + 2 * ((al-1) / 2) + 3;
    }

    if(ans1 < ans2)
    {
        ans = ans2;
    }
    else
    {
        ans = ans1;
    }

    cout << ans << endl;

    return 0;
}