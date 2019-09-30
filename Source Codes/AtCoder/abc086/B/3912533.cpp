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
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    string a,b;
    cin >> a >> b;
    int num = stoi(a+b);
    bool ok = false;
    for (int i = 1; i*i <= 100100; i++){
        if (i*i == num){
            ok = true;
        }
    }
    if (ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    

    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.