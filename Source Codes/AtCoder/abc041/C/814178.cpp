#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector<pair<uint32_t, uint32_t>> sinchou(n);
  for(uint32_t i = 0; i < n; i++){
    uint32_t t;
    cin >> t;
    sinchou[i] = {i, t};
  }

  sort(begin(sinchou), end(sinchou),
      [](pair<uint32_t, uint32_t> const& a,
        pair<uint32_t, uint32_t> const& b){
      return a.second > b.second;
      });
  for(auto const& x : sinchou)
    cout << x.first + 1 << endl;
}