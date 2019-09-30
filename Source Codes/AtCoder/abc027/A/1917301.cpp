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
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if(l1 == l2){
        cout << l3 << endl;
    }else if(l2 == l3){
        cout << l1 << endl;
    }else if(l3 == l1){
        cout << l2 << endl;
    }
    return 0;
}