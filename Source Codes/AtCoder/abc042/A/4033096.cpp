#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v(3);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(), v.end());

    if(v[0] == 5 && v[1] == 5 && v[2] == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}