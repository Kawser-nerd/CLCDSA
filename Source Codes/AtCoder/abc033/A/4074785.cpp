#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    char c0, c1;
    bool same = true;
    cin >> c0;
    c1 = c0; cin >> c0; if(c0 != c1) same = false;
    c1 = c0; cin >> c0; if(c0 != c1) same = false;
    c1 = c0; cin >> c0; if(c0 != c1) same = false;
    cout << (same ? "SAME" : "DIFFERENT") << endl;
    return 0;
}