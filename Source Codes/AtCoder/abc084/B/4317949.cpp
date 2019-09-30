#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
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
    int A,B;
    string s;
    cin >> A >> B >> s;

    A--;
    bool ok = true;
    for (int i = 0;  i < (int)s.size(); ++i) {
        if (i == A+1) {
            if (s[i] != '-') {
                ok = false;
            }
        } else {
            int t = s[i];
            if (s[i] == '-') {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}