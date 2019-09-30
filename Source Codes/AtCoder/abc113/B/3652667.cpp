#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

inline int solution(istream &cin, ostream &cout) {
  int n, t, a;
  cin >> n >> t >> a;
  int ans = 10000000;
  double diff = 10000000;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    double d = double(t) -double(x) * 0.006;
    if (diff > fabs(double(a) - d)) {
      ans = i + 1;
      diff = fabs(double(a) - d);
    }
  }
  cout << ans << endl;
  return 0;
}

#if defined(LOCAL_TEST_RUN)

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "gmock/gmock-more-matchers.h"
#include <sstream>

typedef pair<string, string> TestParam;
class ATest : public ::testing::TestWithParam<TestParam> {};

TEST_P(ATest, ExampleTest) {
  string input, expected_output;
  tie(input, expected_output) = GetParam();

  stringstream ss(input);
  stringstream out;
  solution(ss, out);
  EXPECT_THAT(out.str(), ::testing::StartsWith(expected_output));
}

INSTANTIATE_TEST_CASE_P(Case1, ATest, ::testing::Values(
  make_pair(
      /*input=*/R"(2
12 5
1000 2000)",
      /*output=*/R"(1)")
));

INSTANTIATE_TEST_CASE_P(Case2, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"(3
21 -11
81234 94124 52141)",
        /*output=*/R"(3)")
));

INSTANTIATE_TEST_CASE_P(Case3, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"()",
        /*output=*/R"()")
));

INSTANTIATE_TEST_CASE_P(Case4, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"()",
        /*output=*/R"()")
));

INSTANTIATE_TEST_CASE_P(Case5, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"()",
        /*output=*/R"()")
));

INSTANTIATE_TEST_CASE_P(Case6, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"()",
        /*output=*/R"()")
));

#else

int main() {
  return solution(cin, cout);
}

#endif