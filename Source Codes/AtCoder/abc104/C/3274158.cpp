#include <iostream>
#include <algorithm>
#include <climits>
#include <bitset>

using namespace std;

int P[10], p[10], c[10];

int main(void){
    int D, G;
    int sub;
    int ans = INT_MAX;
    
    cin >> D >> G;
    
    for(int i = 0; i < D; i++){
        cin >> sub;
        p[i] = sub;
        cin >> sub;
        c[i] = sub;
    }
    
    // for(int i = 0; i < (1 << D); i++){
    //     cout << bitset<4>(i) << endl;
    // }
    
    for(int i = 0; i < (1 << D); i++){
        int cnt = 0;
        int sum = G;
        
        for(int j = 0; j < D; j++){
            P[j] = p[j];
        }
        
        for(int j = D - 1; j >= 0; j--){
            if(i & (1 << j)){
                cnt += p[j];
                sum -= 100 * (j + 1) * p[j] + c[j];
                P[j] = 0;
            }
            
            if(sum <= 0){
                break;
            }
        }
        
        if(sum > 0){
            for(int j = D - 1; j >= 0; j--){
                if(P[j] > 0){
                    while(P[j] > 0 && sum > 0){
                        cnt++;
                        sum -= 100 * (j + 1);
                        P[j]--;
                    }
                }
                
                if(sum <= 0){
                    break;
                }
            }
        }

        ans = min(ans, cnt);
    }
    
    cout << ans << "\n";
}