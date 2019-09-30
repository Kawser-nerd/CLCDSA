#include <iostream>
#define MAX_N 100000
using namespace std;

typedef long long ll;

ll N;

int main(){
    ll ans = 0, tmp = 1, pre = INT_MAX;

    cin >> N; 
    for(int i = 0; i < N; ++i){
        ll a;
        cin >> a;
        if(a > pre){
            tmp++;
        }else{
            tmp = 1;
        }
        ans += tmp;
        pre = a;
    }
    cout << ans << endl;
    return 0;
}