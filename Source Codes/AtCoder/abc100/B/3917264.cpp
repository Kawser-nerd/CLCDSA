using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
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

int solve(int num){
    int ret = 0;
    while(num % 100 == 0){
        num /= 100;
        ret++;
    }
    return ret;
}
int main(){
    int D,N;
    cin >> D >> N;
    int cnt = 0, num = 0;
    while(cnt < N) {
        num++;
        if (solve(num) == D) cnt++;
    }
    cout << num << endl;

    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.