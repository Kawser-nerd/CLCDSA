#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    int A[N], B[N], C[M], D[M];
    for(int i = 0; i < N; ++i){ cin >> A[i] >> B[i]; }
    for(int i = 0; i < M; ++i){ cin >> C[i] >> D[i]; }

    for(int i = 0; i < N; ++i){
        int maxNum = INT_MAX;
        int ans;
        for(int j = 0; j < M; ++j){
            int temp = abs(A[i] - C[j]) + abs(B[i] - D[j]);
            if(maxNum > temp){ 
                maxNum = temp; 
                ans = j+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}