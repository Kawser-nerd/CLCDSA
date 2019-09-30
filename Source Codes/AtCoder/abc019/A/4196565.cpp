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
    vector<int> v(3);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(), v.end());
    cout << v[1] << endl;
    return 0;
}