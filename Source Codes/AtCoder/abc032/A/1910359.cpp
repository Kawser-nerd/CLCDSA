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
    int a, b, n;
    cin >> a >> b >> n;

    int ans = -1;
    for(int i = n; ; i++){
        if(i % a == 0 && i % b == 0){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}