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
    int N, Q;
    cin >> N >> Q;

    vector<uint64_t> v(N, 0);
    for(int i = 0; i < Q; ++i)
    {
        int li, ri, ti;
        cin >> li >> ri >> ti;
        for(int p = li - 1; p < ri; ++p)
        {
            v[p] = ti;
        }
    }
    for(auto& e : v)
        cout << e << endl;
    return 0;
}