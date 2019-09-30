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
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % N != 0){
        ans = -1;
    } else {
        int numperis = sum / N;
        int t_sum = 0;
        for (int i = 1; i <= N; i++){
            t_sum += a[i-1];
            if (t_sum != numperis * i){
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}