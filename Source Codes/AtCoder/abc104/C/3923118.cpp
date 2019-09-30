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
    int D,G;
    cin >> D >> G;
    vector<int> p(D),c(D);
    for (int i = 0; i < D; i++){
        cin >> p[i] >> c[i];
    }
    ll ans = INT_MAX;
    for (int b = 0; b < (1<<D); b++){
        ll t_G = 0;
        ll t_Q = 0;
        int index = 0;
        for (int i = 0; i < D; i++){
            if (b & (1<<i)){
                t_G += c[i];
                t_G += p[i] * 100 * (i+1);
                t_Q += p[i];
            } else {
                index = i;
            }
        }
        if (t_G < G){
            for (int i = 1; i < p[index]; i++){
                t_G += 100*(index+1);
                t_Q++;
                if (t_G >= G){
                    break;
                }
            }
        }
        if (t_G >= G){
            ans = min(ans,t_Q);
        }
    }
    cout << ans << endl;







    return 0;
}