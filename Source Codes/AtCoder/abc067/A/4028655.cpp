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
    int A,B;
    cin >> A >> B;
    bool ok = false;
    if (A % 3 == 0){
        ok = true;
    } else if (B % 3 == 0){
        ok = true;
    } else if ((A + B) % 3 == 0){
        ok = true;
    }

    if (ok){
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    

    return 0;
}