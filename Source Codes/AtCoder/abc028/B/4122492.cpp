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
    string S;
    cin >> S;

    vector<int> v(6, 0);
    for(const auto& e : S)
    {
        v[e - 'A']++;
    }
    cout << v[0] << ' ';
    cout << v[1] << ' ';
    cout << v[2] << ' ';
    cout << v[3] << ' ';
    cout << v[4] << ' ';
    cout << v[5] << endl;
    return 0;
}