#include <iostream>
#include <cstdint>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
typedef std::multiset<uint64_t> S;

uint64_t target(uint64_t x) {
  int b = 0;
  uint64_t temp = x;
  while(temp > 0) {
    temp = temp >> 1;
    b++;
  }
  return (1ull << (b)) - x;
}

S read() {
  uint64_t N;
  cin >> N;

  S s;
  for(uint64_t i=0; i<N; i++) {
    uint64_t x;
    cin >> x;
    s.insert(x);
  }

  return std::move(s);
}

int solve(S& s) {
  int num_pairs = 0;
  while(s.size() > 0) {
    auto last = s.end();
    last--;
    uint64_t t = target(*last);
    s.erase(last);
    auto found = s.find(t);
    if( found != s.end() ) {
      num_pairs++;
      s.erase(found);
    }
  }
  return num_pairs;
}

void test() {
  S s = {1,2,3};
  assert(solve(s)==1);

  S s2 = {3,11,14,5,13};
  assert(solve(s2)==2);

  S s3 = {1,1,3,7};
  assert(solve(s3) == 2);

  S s4 = {8,8,8,8};
  assert(solve(s4) == 2);

  S s5 = {1,9,5};
  assert(solve(s5) == 0);

  S s6 = {1,3,7,15};
  assert(solve(s6) == 1);
}

int main() {
  S s = read();
  int r = solve(s);
  cout << r << endl;

  return 0;
}