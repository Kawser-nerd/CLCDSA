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
    int N;
    array<array<int,15>,105> F;
    array<array<int,15>,105> P;
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int k = 0; k < 10; k++){
            cin >> F[i][k];
        }
    }
    for (int i = 0; i < N; i++){
        for (int k = 0; k < 11; k++){
            cin >> P[i][k];
        }
    }
    ll ans = -(1<<30);
    for (int b = 1; b < (1<<10); b++){
        ll prof = 0;
        for (int i = 0; i < N; i++){
            int c = 0;
            for (int k = 0; k < 10; k++){
                if (b & (1<<k) && F[i][k]){
                    c++;
                }
            }
            prof += P[i][c];
        }
        ans = max(ans,prof);
    }
    cout << ans << endl;

                    


            




    return 0;
}