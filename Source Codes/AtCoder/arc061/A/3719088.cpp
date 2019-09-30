//#include <algorithm>
#include <array>
//#include <cassert>
//#include <cfloat>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <deque>
#include <iostream>
//#include <limits>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <string>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

string S;

long dfs(int cur, array<char, 10> plus) {
  long result;
  if (cur >= S.size()) {
    long sum{}, num{};
    for (int i{}; i < S.size(); ++i) {
      if (plus[i] == '+') {
//        cerr << num << endl;
        sum += num;
        num = 0;
      }
      num *= 10;
      num += S[i] & 0xF;
    }
    sum += num;
//    cerr << num << endl;
    return sum;
  }
  result = dfs(cur + 1, plus);
  plus[cur] = '+';
  result += dfs(cur + 1, plus);

  return result;
}

int main() {
  cin >> S;
  array<char, 10> plus;
  cout << dfs(1, plus) << endl;

  return 0;
}