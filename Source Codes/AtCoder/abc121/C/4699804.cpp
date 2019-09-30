#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> shop(n);
  for(int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    shop[i] = {a, b};
  }
  sort(shop.begin(), shop.end());
  ll mincost = 0;
  for(int i = 0; i < n; i++) {
    if(m - shop[i].second >= 0)
    {
      m -= shop[i].second;
      mincost += shop[i].first * shop[i].second;
    }else{
      mincost += shop[i].first * m;
      break;
    }
  }
  cout << mincost << endl;
}