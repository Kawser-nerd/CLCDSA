#include <iostream>

using namespace std;

int H, W;

bool in_field(int h, int w){
    if(h < 0 || h >= H || w < 0 || w >= W) return false;
    else return true;
}

int main(){
    
    int x[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int y[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    cin >> H >> W;
    char s[100][100];
    char ans[100][100];
    char test[100][100];
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cin >> s[h][w];
            ans[h][w] = '#';
            test[h][w] = '.';
        }
    }
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(s[h][w] == '.'){
                for(int i = 0; i  < 9; i++){
                    if(in_field(h+x[i], w+y[i])){
                        ans[h+x[i]][w+y[i]] = '.';
                    }
                }
            }
        }
    }
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(ans[h][w] == '#'){
                for(int i = 0; i  < 9; i++){
                    if(in_field(h+x[i], w+y[i])){
                        test[h+x[i]][w+y[i]] = '#';
                    }
                }
            }
        }
    }
    
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(s[h][w] != test[h][w]){
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cout << ans[h][w];
        }
        cout << endl;
    }
}