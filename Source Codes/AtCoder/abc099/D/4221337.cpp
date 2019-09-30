#include <iostream>

using namespace std;

int cnt[3][30];

int main(){
    int N, C;
    int ans = INT32_MAX;
    cin >> N >> C;
    int D[30][30];
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            cin >> D[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int c;
            cin >> c;
            c--;
            cnt[(i+j)%3][c]++;
        }
    }
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(j == i) continue;
            for(int k = 0; k < C; k++){
                if(k == j || k == i) continue;
                int tmp_ans = 0;
                for(int l = 0; l < C; l++){
                    tmp_ans += cnt[0][l]*D[l][i];
                    tmp_ans += cnt[1][l]*D[l][j];
                    tmp_ans += cnt[2][l]*D[l][k];
                }
                ans = min(ans, tmp_ans);
            }
        }
    }
    cout << ans << endl;
}