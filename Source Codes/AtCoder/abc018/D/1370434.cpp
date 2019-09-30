#include <iostream>
#include <vector>
#include <stdio.h>
#include <functional>

using namespace std;
using ull = unsigned long long;
int main(){
    ull N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    int X[R], Y[R], Z[R];
    
    for(ull i = 0; i < R; ++i){
        cin >> X[i] >> Y[i] >> Z[i];
    }

    int ans = 0;
    for(ull i = 0; i < (1 << M); ++i){
        int checkSum = 0;
        ull I = i; 
        while(I){
            if(I & 1){
                checkSum++;
            }
            I >>= 1;
        }
        I = i;
        vector<int> v;
        for(int j = 0; j < N; ++j){
            v.push_back(0);
        }
        if(checkSum == Q){
            int p = 1;
            while(I){
                if(I & 1){
                    for(int k = 0; k < R; ++k){
                        if(Y[k] == p){
                            v[X[k]-1] += Z[k];
                        }
                    }
                    
                }
                p++;
                I >>= 1;
            }
            sort(v.begin(), v.end(), greater<int>());
            int tempAns = 0;
            for(int k = 0; k < P; ++k){
                tempAns += v[k];
            }
            ans = ans < tempAns ? tempAns : ans;
        }
    }

    cout << ans << endl;


    return 0;
}