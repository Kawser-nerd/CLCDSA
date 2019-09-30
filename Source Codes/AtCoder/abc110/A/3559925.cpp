#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;
    int n;

    cin >> n; v.push_back(n);
    cin >> n; v.push_back(n);
    cin >> n; v.push_back(n);

    sort(v.begin(), v.end());

    cout << v[2] * 10 + v[1] + v[0] << endl;

    return 0;
}