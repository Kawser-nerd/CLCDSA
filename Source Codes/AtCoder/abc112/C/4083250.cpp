#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define sz(x) ((int)(x).size())
#define pb push_back
using ll  = long long;
using vi  = vector<int>;

signed main(){
  int n; cin >> n;
  int a,b,c;
  vi x(n),y(n),h(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i]){
      a = x[i]; b = y[i]; c = h[i];
    }
  }
  rep(i,101) rep(j,101){
    int H = abs(i - a) + abs(j - b) + c;
    bool f = true;
    rep(k,n){
      int tmp = abs(i - x[k]) + abs(j - y[k]) + h[k];
      if((h[k] != 0 and H != tmp) or (h[k] == 0 and H > tmp)) f = false;
    }
    if(f){
      cout << i << " " << j << " " << H << endl;
      break;
    }
  }
}