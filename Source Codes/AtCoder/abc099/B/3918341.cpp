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

int solve(int n){
    if (n == 1) return 1;
    return n + solve(n-1);
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << solve(b-a) - b << endl;
    

    return 0;
}