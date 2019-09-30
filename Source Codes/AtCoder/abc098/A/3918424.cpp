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
    vector<int> t(3);
    t[0] = A + B;
    t[1] = A - B;
    t[2] = A * B;

    cout << *max_element(all(t)) << endl;

    return 0;
}