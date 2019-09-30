#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

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
    string s;
    cin >> s;

    bool ans = true;
    int len = s.length();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(s[i] == s[j]){
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "yes" : "no") << endl;

    return 0;
}