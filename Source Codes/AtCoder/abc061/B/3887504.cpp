#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> v(N, 0);
    for(int i = 0; i < M; ++i)
    {
        int ai, bi;
        cin >> ai >> bi;
        v[ai - 1]++;
        v[bi - 1]++;
    }

    for(const auto& e : v)
        cout << e << endl;
    return 0;
}