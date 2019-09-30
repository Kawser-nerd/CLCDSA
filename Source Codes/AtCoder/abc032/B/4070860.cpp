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
    string s;
    int k;
    cin >> s >> k;
    set<string> c;
    for (int i = 0; i + k -1 < (int)s.size(); i++) {
        c.insert(string(s,i,k));
    }

    cout << (int)c.size() << endl;

    



    return 0;
}