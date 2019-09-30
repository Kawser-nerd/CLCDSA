#include <iostream>
#include <cstdint>
#include <vector>
#include <cassert>

using namespace std;
typedef int64_t i_t;

void read(i_t& N) {
  cin >> N;
}

int solve(i_t N) {
  if( N == 3 || N == 5 || N == 7 ) {
    return 1;
  }
  return 0;
}

void test() {
  {
    assert(solve(3)==1);
  }
  {
    assert(solve(4)==0);
  }
  {
    assert(solve(7)==1);
  }
  cerr << "OK" << endl;
}

int main() {
  i_t N;
  read(N);
  int ans = solve(N);
  cout << (ans ? "YES" : "NO") << endl;
  //test();

  return 0;
}