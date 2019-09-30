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
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int sum = a + b + c;
    int m = max(a,max(b,c));
    sum -= m;
    sum += m * pow(2,k);
    cout << sum << endl;

    return 0;
}