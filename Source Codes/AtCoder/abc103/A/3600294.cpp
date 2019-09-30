#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v(3);

    cin >> v[0] >> v[1] >> v[2];

    std::sort(v.begin(), v.end());

    cout << (v[1] - v[0]) + (v[2] - v[1]) << endl;
    return 0;
}