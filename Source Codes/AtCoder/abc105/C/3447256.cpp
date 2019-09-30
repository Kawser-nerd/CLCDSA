#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <map>
#include <cmath>
#include <sstream>

#include <boost/range/irange.hpp>
using boost::irange;

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int64_t n;
    cin >> n;
    
    vector<char> ss;
    
    if(n == 0)
    {
        ss.push_back('0');
    }
    else
    {
        while(n != 0)
        {
            ss.push_back(n % -2 == 0 ? '0' : '1');
            n = n / -2 + (n % -2 == -1 ? 1 : 0);
        }
    }
    
    for(auto c = ss.rbegin(); c != ss.rend(); ++c)
    {
        cout << *c;
    }   
    cout << '\n';

    return 0;
}