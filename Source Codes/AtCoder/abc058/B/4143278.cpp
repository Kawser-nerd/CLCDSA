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
    string O, E;
    cin >> O >> E;
    for (int i = 0; i < O.size(); ++i) {
        cout << O[i];
        if (i < E.size()) {
            cout << E[i];
        }
    }
    cout << endl;
}