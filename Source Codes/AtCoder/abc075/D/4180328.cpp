#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    long x[50];
    long y[50];
    long ans = __LONG_MAX__;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            long x1, y1, x2, y2;
            x1 = min(x[i], x[j]);
            y1 = min(y[i], y[j]);
            x2 = max(x[i], x[j]);
            y2 = max(y[i], y[j]);
            int cnt = 0;
            for(int m = 0; m < N; m++){
                if(x[m] >= x1 && x[m] <= x2 && y[m] >= y1 && y[m] <= y2) cnt++;
            }
            if(cnt >= K) ans = min(ans, (x2-x1)*(y2-y1));
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                long x1, y1, x2, y2;
                x1 = min(min(x[i], x[j]), x[k]);
                y1 = min(min(y[i], y[j]), y[k]);
                x2 = max(max(x[i], x[j]), x[k]);
                y2 = max(max(y[i], y[j]), y[k]);
                int cnt = 0;
                for(int m = 0; m < N; m++){
                    if(x[m] >= x1 && x[m] <= x2 && y[m] >= y1 && y[m] <= y2) cnt++;
                }
                //cout << (x2-x1)*(y2-y1) << endl;
                if(cnt >= K) ans = min(ans, (x2-x1)*(y2-y1));
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                for(int l = 0; l < k; l++){
                    long x1, y1, x2, y2;
                    x1 = min(min(x[i], x[j]), min(x[k], x[l]));
                    y1 = min(min(y[i], y[j]), min(y[k], y[l]));
                    x2 = max(max(x[i], x[j]), max(x[k], x[l]));
                    y2 = max(max(y[i], y[j]), max(y[k], y[l]));
                    int cnt = 0;
                    for(int m = 0; m < N; m++){
                        if(x[m] >= x1 && x[m] <= x2 && y[m] >= y1 && y[m] <= y2) cnt++;
                    }
                    //cout << (x2-x1)*(y2-y1) << endl;
                    if(cnt >= K) ans = min(ans, (x2-x1)*(y2-y1));
                }
            }
        }
    }
    cout << ans << endl;
}