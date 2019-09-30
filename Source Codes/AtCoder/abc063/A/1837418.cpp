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
    int a, b;
    cin >> a >> b;

    if(a + b >= 10){
        cout << "error" << endl;
    }else{
        cout << (a + b) << endl;
    }

    return 0;
}