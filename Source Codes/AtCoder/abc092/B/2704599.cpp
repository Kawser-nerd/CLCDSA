#include<iostream>
#include<vector>
using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, D, X;
    vector<int> A;
    cin >> N;
    cin >> D >> X;
    A.resize(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int ans = X;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++){
            if((j * A[i] + 1) <= D){
                ans++;
            }
            else{
                continue;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}