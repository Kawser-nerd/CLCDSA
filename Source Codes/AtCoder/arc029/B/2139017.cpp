#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

bool check(double a, double b, double c, double d){
    double l = 0;
    double r = M_PI / 2;
    for(int i = 0; i < 200; i++){
        double m = (l + r) / 2;
        double h = a*cos(m) + b*sin(m);
        double w = a*sin(m) + b*cos(m);
        if(h <= c && w <= d){
            return true;
        }
        if(h < c){
            l = m;
        }else{
            r = m;
        }
    }
    return false;
}

signed main(){
    double a, b;
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }

    int n;
    cin >> n;
    rep(i, n){
        double c, d;
        cin >> c >> d;

        if(a <= c && b <= d || a <= d && b <= c || check(a, b, c, d) || check(a, b, d, c)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
} ./Main.cpp:51:19: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(a <= c && b <= d || a <= d && b <= c || check(a, b, c, d) || check(a, b, d, c)){
           ~~~~~~~^~~~~~~~~ ~~
./Main.cpp:51:19: note: place parentheses around the '&&' expression to silence this warning
        if(a <= c && b <= d || a <= d && b <= c || check(a, b, c, d) || check(a, b, d, c)){
                  ^
           (               )
./Main.cpp:51:39: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(a <= c && b <= d || a <= d && b <= c || check(a, b, c, d) || check(a, b, d, c)){
                            ~~ ~~~~~~~^~~~~~~~~
./Main.cpp:51:39: note: place parentheses around the '&&' expression to silence this warning
        if(a <= c && b <= d || a <= d && b <= c || check(a, b, c, d) || check(a, b, d, c)){
                                      ^
                               (               )
2 warnings generated.