#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {
    string A, B;
    cin >> A;
    cin >> B;

    if (A.size() >= B.size() && A > B) {
        cout << "GREATER" << endl;
    } else if (A == B) {
        cout << "EQUAL" << endl;
    } else {
        cout << "LESS" << endl;
    }
}