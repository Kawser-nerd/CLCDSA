#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    vector<int> v = {A, B, C};
    sort(v.begin(), v.end());
    cout << (v[0] + v[1] + v[2] * (1 << K)) << endl;
    return 0;
}