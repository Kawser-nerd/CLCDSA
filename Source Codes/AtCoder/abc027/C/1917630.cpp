#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    bool ans = true;
    ll m = n + 1;
    while(m > 1){
        if(ans){
            if(m % 2 == 0){
                m /= 2;
            }else{
                m /= 2;
                m++;
            }
        }else{
            m /= 2;
        }
        ans = !ans;
    }

    cout << (ans ? "Takahashi" : "Aoki") << endl;
    return 0;
}