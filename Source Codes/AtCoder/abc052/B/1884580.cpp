#include <algorithm>
#include <cctype>
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

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    int x = 0;
    for(char c : s){
        if(c == 'I'){
            x++;
        }else{
            x--;
        }
        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}