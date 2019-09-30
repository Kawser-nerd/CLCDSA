#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N;
    vector<int> T(N);
    int s = 0;
    for(auto& e : T)
    {
        cin >> e;
        s += e;
    }

    cin >> M;
    vector<pair<int, int>> P(M);
    for(auto& e : P)
        cin >> e.first >> e.second;

    for(const auto& e : P)
    {
        cout << s - T[e.first - 1] + e.second << endl;
    }

    return 0;
}