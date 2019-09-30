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
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    bool ok = true;
    if (a[(int)a.size()-1] != b[0]){
        ok = false;
    } else if (b[(int)b.size()-1] != c[0]){
        ok = false;
    }

    if (ok){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}