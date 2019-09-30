#include <iostream>

using namespace std;

int main(){
    int N, M;
    bool red[100000];
    int cnt[100000];
    cin >> N >> M;
    red[0] = true;
    cnt[0] = 1;
    for(int i = 1; i < N; i++){
        red[i] = false;
        cnt[i] = 1;
    }
    bool flag = false;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt[x]--;
        cnt[y]++;
        if(red[x]) red[y] = true;
        if(cnt[x] == 0) red[x] = false;
        if(x == 0 && !flag) red[x] = false;
        if(y == 0) flag = true;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(red[i] && cnt[i] > 0) ans++;
    }
    cout << ans << endl;
}