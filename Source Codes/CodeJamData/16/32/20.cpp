/* This is template part for Google CodeJam contest
 * created by Shapovalov Nikita, 2016
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace CodeJamUtility {

    class TestCaseUtil
    {
        std::clock_t start_test_time;

        int test_id_;
        int precision_;

        std::stringstream ss;

    public:
        TestCaseUtil(int test_id, int precision = 10) : 
            start_test_time(std::clock()), 
            test_id_(test_id), 
            precision_(precision),
            ss()
        {
            std::cerr << "Processing test #" << std::setw(4) << test_id << ": ";
            ss << std::fixed << std::setprecision(precision_);
        }

        TestCaseUtil(const TestCaseUtil &) = delete;

        TestCaseUtil &operator=(const TestCaseUtil &) = delete;

        ~TestCaseUtil()
        {
            std::cerr << "Ok. Time elapsed: " << std::setw(5) << 
                (std::clock() - start_test_time) / (1. * CLOCKS_PER_SEC) << " secs" << std::endl;
            std::cout << "Case #" << test_id_ << ": " << ss.str() << "\n";
        }

        template< class T >
        friend TestCaseUtil &operator<<(TestCaseUtil &, const T &obj);

    };

    template< class T >
    TestCaseUtil &
    operator<<(TestCaseUtil &t, const T &obj)
    {
        t.ss << obj;
        return t;
    }
}

#define EXECUTE_FUNCTION(NAME) \
    process(CodeJamUtility::TestCaseUtil & NAME)

#define CODEJAM_RUN_NEW_TEST(ID, NAME) \
    {\
        CodeJamUtility::TestCaseUtil NAME(ID);\
        process(NAME);\
    }

#define CODEJAM_RUN_ALL_TESTS(NAME)\
int main() \
{\
    std::ios_base::sync_with_stdio(false); \
    int testNumber##NAME;\
    std::cin >> testNumber##NAME;\
    for (int counter##NAME = 1; counter##NAME <= testNumber##NAME; ++counter##NAME) {\
        CODEJAM_RUN_NEW_TEST(counter##NAME, NAME);\
    }\
    return 0;\
}

#include <bits/stdc++.h>

using namespace std;

/* End of template part */

typedef int64_t ll;

void
EXECUTE_FUNCTION(out)
{
    int b;
    ll m;
    cin >> b >> m;
    if ((ll(1) << (b - 2)) < m) {
        out << "IMPOSSIBLE";
    } else {
        out << "POSSIBLE";
        vector< vector< int > > mt(b, vector< int >(b, 0));
        for (int i = 0; i < b - 1; ++i) {
            for (int j = i + 1; j < b - 1; ++j) {
                mt[i][j] = 1;
            }
        }
        mt[0].back() = 1;
        m--;
        for (int i = 1; i < b - 1; ++i) {
            if (m & (ll(1) << (i - 1))) {
                mt[i].back() = 1;
            }
        }
        for (int i = 0; i < b; ++i) {
            out << "\n";
            for (int j = 0; j < b; ++j) {
                out << mt[i][j];
            }
        }
    }
}

CODEJAM_RUN_ALL_TESTS(Qual_2015_)
