#include <iostream>
#include <set>

using namespace std;

int main()
{
    size_t n;
    set<int> s;

    cin >> n;
    for (auto i = 0u; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }

    auto i = end(s);
    --i;
    --i;

    cout << *i << endl;

    return 0;
}