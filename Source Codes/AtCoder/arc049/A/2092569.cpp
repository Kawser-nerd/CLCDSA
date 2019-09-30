#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    string s;
    int a, b, c, d;
    cin >> s >> a >> b >> c >> d;

    cout << s.substr(0, a) << '"' << s.substr(a, b-a) << '"' << s.substr(b, c-b) << '"' << s.substr(c, d-c) << '"' << s.substr(d, s.size()-d) << endl;

    return 0;
}