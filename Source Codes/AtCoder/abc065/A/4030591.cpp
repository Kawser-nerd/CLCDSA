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
    int x,a,b;
    cin >> x >> a >> b;
    if (b <= a){
        cout << "delicious" << endl;
    } else {
        if (b - a <= x){
            cout << "safe" << endl;
        } else {
            cout << "dangerous" << endl;
        }
    }




    return 0;
}