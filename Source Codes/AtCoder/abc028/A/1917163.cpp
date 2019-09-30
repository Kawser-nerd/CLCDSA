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
    int n;
    cin >> n;

    if(n <= 59){
        cout << "Bad" << endl;
    }else if(n <= 89){
        cout << "Good" << endl;
    }else if(n <= 99){
        cout << "Great" << endl;
    }else{
        cout << "Perfect" << endl;
    }


    return 0;
}