#include <iostream>

using namespace std;

long a[2000];
    long m[2000][2000];

int main(){
    int N, x;
    cin >> N >> x;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    long ans = __LONG_MAX__;
    for(int i = 0; i < N; i++){
        m[i][0] = a[i];
        for(int j = 1; j < N; j++){
            if(i >= j) m[i][j] = min(m[i][j-1], a[i-j]);
            else m[i][j] = min(m[i][j-1], a[i-j+N]);
        }
    }
    for(int i = 0; i < N; i++){
        long tmp = 0;
        for(int j = 0; j < N; j++){
            tmp += m[j][i];
        }
        ans = min(ans, tmp+x*i);
    }
    cout << ans << endl;
}