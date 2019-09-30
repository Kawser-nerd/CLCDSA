#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include <cmath>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y;
    cin >> x >> y;

    int ans = 2000000000;
    if(x <= y)   ans = min(ans,y-x);
    if(-x <= y)  ans = min(ans,y+x+1);
    if(-x <= -y) ans = min(ans,x-y+2);
    if(x <= -y)  ans = min(ans,-y-x+1);
    cout << ans << endl;

}