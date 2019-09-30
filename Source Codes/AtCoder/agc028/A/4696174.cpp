#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
 
using namespace std;
using ll = long long int;


template <typename number>
pair<number, number> extended_euclid(number a, number b)
{
    number r0, r1, a0, a1, b0, b1;
    r0 = a; r1 = b;
    a0 = 1; a1 = 0;
    b0 = 0; b1 = 1;
    while (r1>0) {
        number q1 = r0 / r1;
        number r2 = r0 % r1;
        number a2 = a0 - q1 * a1;
        number b2 = b0 - q1 * b1;
        r0 = r1 ; r1 = r2;
        a0 = a1 ; a1 = a2;
        b0 = b1 ; b1 = b2;
    }
    number c = r0;
    a = a0; //x
    b = b0; //y
    return  {a, c};
}



ll calcLCM(ll a, ll b) {
  pair<ll, ll> result = extended_euclid(a, b);
  return a * b / result.second;
}
 
int main()
{
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  ll lcm = calcLCM(n, m);
  ll alpha = lcm / n;
  ll beta = lcm / m;
  map<ll, char> exist;
  exist[1] = s[0];
  for(ll i = 1; i < n; i++)
  {
    ll index = 1 + i * alpha;
    exist[index] = s[i];
  }
  bool can = true;
  if(s[0] != t[0]) can = false;
  for(ll i = 1; i < m; i++)
  {
    ll index = 1 + i * beta;
    if(exist.count(index)){
      if(exist[index] != t[i]) can = false;
    }
  }
  if(can) {
    cout << lcm << endl;
  }else{
    cout << -1 << endl;
  }
}