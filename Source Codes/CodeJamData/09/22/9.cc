#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "B"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool HasNextSameDigitCount(const string& number) {
  for (int i = 0; i + 1 < number.length(); ++i) {
    if (number[i] < number[i + 1]) {
      return true;
    }
  }
  return false;
}

string GetSmallestByDigitCounts(const vector<int>& digit_counts) {
  string result = "";
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < digit_counts[i]; ++j) {
      result += ('0' + i);
    }
  }
  return result;
}

string GetSmallestMoreDigits(const string& number) {
  vector<int> digit_counts(10);
  for (int i = 0; i < number.length(); ++i) {
    ++digit_counts[number[i] - '0'];
  }
  digit_counts[0]++;
  int first = -1;
  for (int i = 1; i < 10; ++i) {
    if (digit_counts[i] > 0) {
      first = i;
      break;
    }
  }
  assert(first != -1);
  string result;
  result += ('0' + first);
  digit_counts[first]--;
  result += GetSmallestByDigitCounts(digit_counts);
  return result;
}

string GetNextNumber(const string& number) {
  if (!HasNextSameDigitCount(number)) {
    return GetSmallestMoreDigits(number);
  }
  for (int first = (int)number.length() - 1; first >= 0; --first) {
    if (HasNextSameDigitCount(number.substr(first))) {
      vector<int> digit_counts(10, 0);
      for (int i = first; i < number.length(); ++i) {
        ++digit_counts[number[i] - '0'];
      }
      int current_first = number[first] - '0';
      int new_first = -1;
      for (int i = current_first + 1; i < 10; ++i) {
        if (digit_counts[i] > 0) {
          new_first = i;
          break;
        }
      }
      assert(new_first != -1);
      string result = number.substr(0, first);
      result += ('0' + new_first);
      digit_counts[new_first]--;
      result += GetSmallestByDigitCounts(digit_counts);
      return result;
    }
  }
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_number = 0; test_number < tests; ++test_number) {
    string number;
    cin >> number;
    cout << "Case #" << test_number + 1 << ": " << GetNextNumber(number) << endl;
  }
  return 0;
}
