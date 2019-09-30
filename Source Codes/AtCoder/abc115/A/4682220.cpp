#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;


int main(void) {
    int d;
    cin >> d;
    switch(d) {
        case 25:
            cout << "Christmas" << endl;
            break;
        case 24:
            cout << "Christmas Eve" << endl;
            break;
        case 23:
            cout << "Christmas Eve Eve" << endl;
            break;
        case 22:
            cout << "Christmas Eve Eve Eve" << endl;
            break;
    }
    return 0;
}