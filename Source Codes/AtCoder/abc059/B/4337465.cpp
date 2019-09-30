#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    string a,b;
    cin >> a >> b;
    int s = (int)a.size() - (int)b.size();
    if (s == 0) {
        s = a.compare(b);
    }
    if (s > 0) {
        cout << "GREATER" << endl;
    } else if (s < 0) {
        cout << "LESS" << endl;
    } else {
        cout << "EQUAL" << endl;
    }

    return 0;
}