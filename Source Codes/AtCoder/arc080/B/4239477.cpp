#include <iostream>

using namespace std;

int main(){
    int H, W;
    int N;
    cin >> H >> W;
    cin >> N;
    int a[10000];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int c[100][100];
    int cnt = a[0];
    int tmp = 1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i%2 == 0){
                c[i][j] = tmp;
            }else{
                c[i][W-j-1] = tmp;
            }
            cnt--;
            if(cnt == 0){
                tmp++;
                cnt = a[tmp-1];
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << c[i][j];
            if(j < W-1) cout << ' ';
        }
        cout << endl;
    }
}