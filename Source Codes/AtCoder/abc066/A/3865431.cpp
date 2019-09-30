#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v(3);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(), v.end());
    cout << v[0] + v[1] << endl;
    return 0;
}