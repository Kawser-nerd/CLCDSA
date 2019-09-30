#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>

using std::cin;
using std::cout;
using std::endl;

using std::min;
using std::max;
using std::abs;

using std::vector;

int main(void) {
    int x, a, b;
    cin >> x >> a >> b;

    char c = '-';
    if(abs(a - x) <= abs(b - x)){
        c = 'A';
    }else{
        c = 'B';
    }
    cout << c << endl;

    return 0;
}