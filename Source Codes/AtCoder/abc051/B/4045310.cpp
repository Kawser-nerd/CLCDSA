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
    int K,S;
    cin >> K >> S;
    int ans = 0;
    for (int i = 0; i <= K; i++){
        int x = i;
        for (int k = 0; k <= K; k++){
            int y = k;
            int z = S-x-y;
            if (z >= 0 && z <= K) ans++;
        }
    }
    cout << ans << endl;



    return 0;
}