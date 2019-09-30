#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D), S(K), T(K);
    for(int i=0; i<D; i++) cin >> L[i] >> R[i];
    for(int i=0; i<K; i++) cin >> S[i] >> T[i];
    for(int i=0; i<K; i++){
        bool right = false;
        if(S[i] < T[i]) right = true;
        int s = S[i];
        for(int j=0; j<D; j++){
            if(right){
                if(L[j] <= s && s < R[j]) s = R[j];
                if(T[i] <= s){
                    cout << j + 1 << endl;
                    break;
                }
            }else{
                if(L[j] < s && s <= R[j]) s = L[j];
                if(s <= T[i]){
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}