#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int N, M;
    map<string, int> m;

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        string si;
        cin >> si;
        auto p = m.insert(make_pair(si, 1));
        if(!p.second)
        {
            p.first->second++;
        }
    }
    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        string ti;
        cin >> ti;
        auto p = m.insert(make_pair(ti, -1));
        if(!p.second)
        {
            p.first->second--;
        }
    }

    int X = -100;
    for(const auto& e : m)
    {
        if(X < e.second)
            X = e.second;
    }

    cout << (X >= 0 ? X : 0) << endl;

    return 0;
}