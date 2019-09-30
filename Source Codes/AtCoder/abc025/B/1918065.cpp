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
    int n, a, b;
    cin >> n >> a >> b;

    int x = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int d;
        cin >> d;
        if(d < a){
            d = a;
        }
        if(d > b){
            d = b;
        }
        if(s == "East"){
            x += d;
        }else if(s == "West"){
            x -= d;
        }
    }

    if(x > 0){
        cout << "East " << x << endl;
    }else if(x < 0){
        cout << "West " << -x << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}