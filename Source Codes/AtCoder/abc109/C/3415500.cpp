#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <map>
#include <cmath>
 

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
  int64_t c;
  while(a)
  {
     c = a; a = b%a; b = c;
  }
  return b;
}
 
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int64_t n;
    cin >> n;
    
    vector<int64_t> xs(n+1);
    for(auto& x : xs)
        cin >> x;
    
    sort(begin(xs), end(xs));

    vector<int64_t> dxs(n);
    for(size_t i = 0; i < dxs.size(); ++i)
        dxs[i] = abs(xs[i+1] - xs[i]);
        
    cout << accumulate(begin(dxs), end(dxs), dxs[0], gcd) << '\n';
    
    return 0;
}