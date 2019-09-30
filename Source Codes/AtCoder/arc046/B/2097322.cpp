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

    if(a < b && n > a || a == b && n % (a+1) == 0){
        cout << "Aoki" << endl;
        return 0;
    }

    cout << "Takahashi" << endl;

    return 0;
} ./Main.cpp:21:14: warning: '&&' within '||' [-Wlogical-op-parentheses]
    if(a < b && n > a || a == b && n % (a+1) == 0){
       ~~~~~~^~~~~~~~ ~~
./Main.cpp:21:14: note: place parentheses around the '&&' expression to silence this warning
    if(a < b && n > a || a == b && n % (a+1) == 0){
             ^
       (             )
./Main.cpp:21:33: warning: '&&' within '||' [-Wlogical-op-parentheses]
    if(a < b && n > a || a == b && n % (a+1) == 0){
                      ~~ ~~~~~~~^~~~~~~~~~~~~~~~~
./Main.cpp:21:33: note: place parentheses around the '&&' expression to silence this warning
    if(a < b && n > a || a == b && n % (a+1) == 0){
                                ^
                         (                       )
2 warnings generated.