#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <array>
#include <fstream>
#include <float.h>
#include <memory>
#include <functional>
#include <iomanip>
#include <queue>
#include <random>
#include <map>
#include <set>

#pragma warning(disable:4996)

using namespace std;

int main() {
  int n, i = 0;
  cin >> n;
  vector<pair<int, int>> student(n);
  for (auto&& v : student) {
    cin >> v.first;
    v.second = ++i;
  }
  sort(student.begin(), student.end(), [](auto& v1, auto& v2) {return v1.first > v2.first; });
  for (auto&& v : student) {
    cout << v.second << endl;
  }
  return 0;
}