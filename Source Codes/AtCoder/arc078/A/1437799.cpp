#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll INF = 100000000000;

int main(){
    int N;
    vector<ll> a;
    cin >> N;
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
        total += tmp;
    }
    
    ll min_num = INF;
    ll x = 0;
    for(int i = 0; i < N - 1; i++){
        x += a[i];
        ll tmp = abs(2*x - total);
        min_num = min(tmp, min_num);
    }
    cout << min_num << endl;
    return 0;
}