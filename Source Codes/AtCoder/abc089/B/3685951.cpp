#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    set<char> s;
    for(int i = 0; i < N; ++i)
    {
        char si;
        cin >> si;
        s.insert(si);
    }

    cout << (3 == s.size() ? "Three" : "Four") << endl;

    return 0;
}