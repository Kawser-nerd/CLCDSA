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
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    double sMax = *max_element(s.begin(), s.end());
    double sMin = *min_element(s.begin(), s.end());
    double diff = sMax - sMin;

    if(diff == 0 && b > 0 || diff > 0 && b == 0){
        cout << -1 << endl;
        return 0;
    }

    double p = (double)b / (double)diff;
    double ss = 0;
    for(int i = 0; i < n; i++){
        s[i] *= p;
        ss += s[i];
    }
    ss /= n;

    cout << fixed << setprecision(6) << p << " " << fixed << setprecision(6) << a - ss << endl;;

    return 0;
} ./Main.cpp:29:18: warning: '&&' within '||' [-Wlogical-op-parentheses]
    if(diff == 0 && b > 0 || diff > 0 && b == 0){
       ~~~~~~~~~~^~~~~~~~ ~~
./Main.cpp:29:18: note: place parentheses around the '&&' expression to silence this warning
    if(diff == 0 && b > 0 || diff > 0 && b == 0){
                 ^
       (                 )
./Main.cpp:29:39: warning: '&&' within '||' [-Wlogical-op-parentheses]
    if(diff == 0 && b > 0 || diff > 0 && b == 0){
                          ~~ ~~~~~~~~~^~~~~~~~~
./Main.cpp:29:39: note: place parentheses around the '&&' expression to silence this warning
    if(diff == 0 && b > 0 || diff > 0 && b == 0){
                                      ^
                             (                 )
2 warnings generated.