#include <iostream>
using namespace std;

int main(){
    int n, m, x, y;
    bool con[12][12] = {};
    
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        con[x - 1][y - 1] = con[y - 1][x - 1] = true;
    }

    //for(int i = 1 << n; i >= 0; i--){
    int ans = 0;
    for(int S = 1 << n; --S; ){
        int t = bitset<32>(S).count();
        if(t <= ans){ continue; }
        
        bool ok = true;
        for(int j = 0; j < n; ++j)
        for(int k = 0; k < j; ++k){
            if(S >> j & S >> k & 1 && !con[j][k]){
                ok = false;
            }
        }
        if(ok) ans = t;
        
    }

    cout << ans << endl;
    
    return 0;
}