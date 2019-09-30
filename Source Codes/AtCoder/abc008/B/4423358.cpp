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
    int N;
    cin >> N;
    map<string, int> m;
    for(int i = 0; i < N; ++i)
    {
        string si;
        cin >> si;
        auto r = m.insert(make_pair(si, 1));
        if(!r.second)
            r.first->second++;
    }

    pair<string, int> p = *m.begin();
    for(const auto& e : m)
    {
        if(e.second >= p.second)
            p = e;
    }

    cout << p.first << endl;
    return 0;
}