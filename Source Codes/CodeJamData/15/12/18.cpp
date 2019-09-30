#include <iostream>
using namespace std;

typedef long long ll;
ll barb[1005];

int T;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        ll B, K, S = 1ll << 50;
        cin >> B >> K; 

        for(int i=0; i<B; i++){
            cin >> barb[i];
            S = min(S, barb[i]);
        }

        ll lo = 0, hi = S * K, tm = 0, tk = K;

        while(lo <= hi){
            ll mi = (lo + hi) / 2;
            
            ll pp = 0;
            for(int i=0; i<B; i++)
                pp += (mi + barb[i] - 1) / barb[i];

            if(pp >= K)
                hi = mi-1;
            else{
                tm = mi;
                tk = pp;
                lo = mi+1;
            }
        }

        int who = -1;
        for(int i=0; i<B; i++)
            if(tm % barb[i] == 0){
                tk++;
                if(tk == K){
                    who = i;
                    break;
                }
            }

        cout << "Case #" << t << ": " << who+1 << "\n";
    }


}
