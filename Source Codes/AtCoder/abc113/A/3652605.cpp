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

using namespace std;

inline int solution(istream &cin, ostream &cout) {
  int a, b;
  cin >> a >> b;
  cout << a + b / 2 << endl;
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
      /*input=*/R"(81 58)",
      /*output=*/R"(110)")
));

INSTANTIATE_TEST_CASE_P(Case2, ATest, ::testing::Values(
    make_pair(
        /*input=*/R"(4 54)",
        /*output=*/R"(31)")
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