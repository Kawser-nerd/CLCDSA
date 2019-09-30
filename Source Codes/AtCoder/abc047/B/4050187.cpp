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

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int W,H,N;
    cin >> W >> H >> N;
    vector<int> x(N),y(N),a(N);
    int xl = 0,xr = W,yb = 0,yt = H;
    for (int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> a[i];
        if (a[i] == 1){
            xl = max(xl,x[i]);
        } else if (a[i] == 2){
            xr = min(xr,x[i]);
        } else if (a[i] == 3){
            yb = max(yb,y[i]);
        } else if (a[i] == 4){
            yt = min(yt,y[i]);
        }
    }
    int w = max(xr - xl,0),h = max(yt - yb,0);
    cout << h * w << endl;



    return 0;
}