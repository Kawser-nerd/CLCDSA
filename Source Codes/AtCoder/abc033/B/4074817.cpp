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
    int N;
    cin >> N;

    vector<pair<string, int>> v(N);
    int sum = 0;
    for(auto& e : v)
    {
        cin >> e.first >> e.second;
        sum += e.second;
    }
    sum /= 2;
    string ans = "atcoder";
    for(auto& e : v)
    {
        if(sum < e.second)
        {
            ans = e.first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}