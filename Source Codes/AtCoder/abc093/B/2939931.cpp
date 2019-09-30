#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, k; cin >> a >> b >> k;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        if (a + i >= a && a + i <= b) v.push_back(a + i);
    }

    for (int i = 0; i < k; i++) {
        if (b - i > 0 && b - i <= b && b - i >= a) v.push_back(b - i);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int x : v) cout << x << endl;
    return 0;
}