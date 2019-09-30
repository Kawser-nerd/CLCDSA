#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <map>
#include <cmath>

#include <boost/range/irange.hpp>
using boost::irange;

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    uint64_t k;
    cin >> k;
    
    if(k <= s.size())
    {
        const auto ir = irange<uint64_t>(0, k);
        if(all_of(begin(ir), end(ir), [&](auto i){ return s[i] == '1'; }))
        {
            cout << "1\n";
            return 0;
        }
    }
    cout << *find_if(begin(s), end(s), [](char c){ return c != '1'; }) << '\n';

    return 0;
}