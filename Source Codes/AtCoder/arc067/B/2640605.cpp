#include <iostream>

#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    ll total = 0;

    ll last;
    cin >> last;

    while (--N)
    {
        ll next;
        cin >> next;

        auto dist = next - last;
//cout << "dist = " << dist << ", Adist = " << A*dist << endl;
        total += (A*dist) > B ? B : A*dist;
//cout << "new total = " << total << endl;
        last = next;
    }

    cout << total << endl;

    return 0;
}