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
  map<int, int, greater<>> student;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int height;
    cin >> height;
    student[height] = i + 1;
  }
  for (auto&& v : student) {
    cout << v.second << endl;
  }
  return 0;
}