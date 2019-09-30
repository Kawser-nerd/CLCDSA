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
    int dx = tx - sx,dy = ty - sy;
    ans += string(dy,'U')+string(dx,'R')+string(dy,'D')+string(dx,'L');
    ans += 'L';
    ans += string(dy+1,'U') + string(dx+1,'R');
    ans += 'D'; 
    ans += 'R'; 
    ans += string(dy+1,'D') + string(dx+1,'L');
    ans += 'U';
    cout << ans << endl;


    return 0;
}