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
    int L, H, N;
    cin >> L >> H >> N;

    vector<int> v(N);
    for(auto& e : v)
        cin >> e;
    for(auto& e : v)
    {
        if(e < L)
            cout << L - e << endl;
        else if(H < e)
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}