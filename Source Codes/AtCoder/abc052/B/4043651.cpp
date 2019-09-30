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
    int n;
    string s;
    cin >> n >> s;

    int maxN = 0,sum = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'I'){
            sum++;
        } else {
            sum--;
        }
        maxN = max(maxN, sum);
    }
    cout << maxN << endl;

    return 0;
}