#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

int main(void) {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;

    string ans;
    ans.push_back(toupper(s1.front()));
    ans.push_back(toupper(s2.front()));
    ans.push_back(toupper(s3.front()));
    cout << ans << endl;
    return 0;
}