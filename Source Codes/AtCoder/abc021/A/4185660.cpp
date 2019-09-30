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

    vector<int> d;
    int m = 1;
    while(N)
    {
        if(N & 1)
            d.push_back(m);
        N >>= 1;
        m <<= 1;
    }
    cout << d.size() << endl;
    for(auto& e : d)
        cout << e << endl;
    return 0;
}