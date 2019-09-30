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
    int a,b;
    char op;
    cin >> a >> op >> b;
    if (op == '+'){
        cout << a+b << endl;
    } else {
        cout << a-b << endl;
    }

    return 0;
}