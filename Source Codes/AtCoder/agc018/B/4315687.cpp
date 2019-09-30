#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int A[300][300];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    int cnt[300];
    int ans = 500;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cnt[j] = 0;
        }
        for(int j = 0; j < N; j++){
            cnt[A[j][0]-1]++;
        }
        int cnt_max = 0;
        int max_idx;
        for(int j = 0; j < M; j++){
            if(cnt_max < cnt[j]){
                cnt_max = cnt[j];
                max_idx = j;
            }
        }
        ans = min(ans, cnt_max);
        for(int j = 0; j < N; j++){
            bool flag = false;
            for(int k = 0; k < M-1; k++){
                if(A[j][k] == max_idx+1) flag = true;
                if(flag){
                    A[j][k] = A[j][k+1];
                }
            }
        }
    }
    cout << ans << endl;
}