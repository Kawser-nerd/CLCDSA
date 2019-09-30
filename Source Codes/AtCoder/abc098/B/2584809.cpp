#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

char buf[105];

int main() {
  int len;
  scanf("%d\n%s", &len, buf);
  int ret = 0;
  for(int pref = 1; pref < len; pref++) {
    set<char> a, b;
    for(int i = 0; i < len; i++) {
      if(i < pref) {
        a.insert(buf[i]);
      }
      else {
        b.insert(buf[i]);
      }
    }
    int curr = 0;
    for(char c: a) {
      if(b.count(c)) {
        curr++;
      }
    }
    ret = max(ret, curr);
  }
  printf("%d\n", ret);
  return 0;
}