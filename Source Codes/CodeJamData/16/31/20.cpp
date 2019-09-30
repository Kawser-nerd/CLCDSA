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

void
EXECUTE_FUNCTION(out)
{
    int n;
    cin >> n;
    vector< int > p(n, 0);
    for (int &x : p) {
        cin >> x;
    }
    vector< pair< int, int > > vals;
    for (int i = 0; i < n; ++i) {
        vals.push_back(make_pair(p[i], i));
    }
    sort(vals.rbegin(), vals.rend());
    while (vals[0].first > vals[1].first) {
        vals[0].first--;
        out << char('A' + vals[0].second) << ' ';
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < vals[i].first; ++j) {
            out << char('A' + vals[i].second) << ' ';
        }
    }
    for (int j = 0; j < vals[0].first; ++j) {
        out << char('A' + vals[0].second) << char('A' + vals[1].second) << ' ';
    }
}

CODEJAM_RUN_ALL_TESTS(Qual_2015_)
