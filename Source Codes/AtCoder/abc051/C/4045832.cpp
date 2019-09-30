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
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    string ans;
    int dx = tx-sx,dy = ty-sy;
    for (int i = 0; i < dy; i++){
        ans += 'U';
    }

    for (int i = 0; i < dx; i++){
        ans += 'R';
    }

    for (int i = 0; i < dy; i++){
        ans += 'D';
    }

    for (int i = 0; i < dx; i++){
        ans += 'L';
    }

    ans += 'L';

    for (int i = 0; i < dy+1; i++){
        ans += 'U';
    }

    for (int i = 0; i < dx+1; i++){
        ans += 'R';
    }

    ans += 'D';
    ans += 'R';

    for (int i = 0; i < dy+1; i++){
        ans += 'D';
    }

    for (int i = 0; i < dx+1; i++){
        ans += 'L';
    }

    ans += 'U';
    cout << ans << endl;





    return 0;
}