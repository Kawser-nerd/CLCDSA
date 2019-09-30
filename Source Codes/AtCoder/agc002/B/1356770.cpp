#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int x[M], y[M];
    for(int i = 0; i < M; ++i){
        cin >> x[i] >> y[i];
    }

    int box[N];
    int prob[N];
    for(int i = 0; i < N; ++i){
        box[i] = 1;
        prob[i] = (i == 0);
    }

    for(int i = 0; i < M; ++i){
        box[x[i]-1]--;
        box[y[i]-1]++;
        if(prob[x[i]-1]){
            prob[y[i]-1] = 1;
        }
        if(box[x[i]-1] == 0){
            prob[x[i]-1] = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; ++i){
        if(prob[i]>=1 && box[i]!=0) ans++;
    }
    cout << ans << endl;
    return 0;
}