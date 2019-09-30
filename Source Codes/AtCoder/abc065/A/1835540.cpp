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
    int x, a, b;
    cin >> x >> a >> b;

    if(b - a > x){
        cout << "dangerous" << endl;
    }else if(b - a > 0){
        cout << "safe" << endl;
    }else{
        cout << "delicious" << endl;
    }

    return 0;
}