#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int a[N], b[N];
    int c[M], d[M];
    for(int i = 0; i < N; ++i){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < M; ++i){
        cin >> c[i] >> d[i];
    }

    
    for(int i = 0; i < N; ++i){
        int ans = 0;
        int minD = INT_MAX;
        for(int j = 0; j < M; ++j){
            int delta = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(delta < minD){
                minD = delta;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }


    return 0;
}