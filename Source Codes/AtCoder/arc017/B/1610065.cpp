#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    if(K == 1){
        cout << N << endl;
        return 0;
    }
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int t = 0;
    int ans = 0;
    for(int i=1; i<N; i++){
        if(A[i] > A[i-1]){
            if(i - t + 1 >= K){
                ans++;
            }
        }else t = i;
    }
    cout << ans << endl;
    return 0;
}