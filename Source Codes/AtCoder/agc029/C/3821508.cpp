#include <iostream>
#include <cstdint>
#include <vector>
#include <set>
#include <map>
#include <cassert>
 
using namespace std;
typedef uint64_t U;
typedef std::vector<U> V;

V read() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  U N;
  cin >> N;
 
  V a(N);
  for(uint64_t i=0; i<N; i++) {
    cin >> a[i];
  }
 
  return std::move(a);
}
 
bool check(const V& a, int k) {

  if(k==1) {
    for(size_t i=1; i<a.size(); i++) {
      if(a[i] <= a[i-1]) { return false; }
    }
    return true;
  }
 
  map<U,U> current;
 
  for(size_t i=1; i<a.size(); i++) {
    if(a[i] <= a[i-1]) {
      U pos = a[i]-1;
      current[pos] = current[pos] + 1;
      while( current[pos] == k && pos > 0 ) {
        pos--;
        current[pos] = current[pos] + 1;
      }
      auto it = current.lower_bound(pos+1);
      current.erase(it, current.end());
      if(current[0] == k) {
        return false;
      }
    }
    else {
      // extend current with zero
    }
  }
  return true;
}
 
int solve(const V& a) {
  int k_ng = 0;
  int k_ok = a.size();
 
  int k = k_ok / 10 + 1;
  while( k_ok - k_ng > 1 ) {
    if( check(a,k) ) {
      k_ok = k;
    }
    else {
      k_ng = k;
    }
    k = (k_ng + k_ok)/2;
  }
 
 
  return k_ok;
}
 
void test() {
  V a1 = {3,2,1};
  assert(solve(a1)==2);
 
  V a2 = {2,3,2,1,2};
  assert(solve(a2)==2);
 
  V a3 = {2,2,2,2,1};
  assert(solve(a3)==3);
 
  V a4 = {3,3,3,3,3,3,3,3};
  assert(solve(a4)==2);
 
  V a5 = {3,3,3,2,1};
  assert(solve(a5)==3);

  {
    V v(100000, 3);
    assert(solve(v)==47);
  }
  {
    V v(100000, 5);
    assert(solve(v)==10);
  }
  {
    V v(200000, 1000000000);
    bool b = check(v, 1);
    assert(b == false);

    bool b2 = check(v, 2);
    assert(b2 == true);
  }
  cerr << "passed" << endl;
}
 
int main() {
  V in = read();
  int r = solve(in);
  cout << r << endl;

  //test();
 
  return 0;
}