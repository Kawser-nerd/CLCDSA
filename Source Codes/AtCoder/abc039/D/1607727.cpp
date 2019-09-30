#include <iostream>
#define MAX_H_W 100
using namespace std;

int H, W;
char field[MAX_H_W][MAX_H_W+1];
char mapped[MAX_H_W][MAX_H_W];
char remapped[MAX_H_W][MAX_H_W];

int main(){
    bool flg = true;
    cin >> H >> W;
    for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j){
        cin >> field[i][j];
        mapped[i][j] = field[i][j];
        remapped[i][j] = '.';
    }

    for(int x = 0; x < H; ++x){
        for(int y = 0; y < W; ++y){
            if(field[x][y] == '.'){
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        int nx = x + dx;
                        int ny = y + dy;
                        if(0 <= nx && nx < H && 0 <= ny && ny < W){
                            mapped[nx][ny] = '.';
                        }
                    }
                }
            }
        }
    }

    for(int x = 0; x < H; ++x){
        for(int y = 0; y < W; ++y){
            if(mapped[x][y] == '#'){
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        int nx = x + dx;
                        int ny = y + dy;
                        if(0 <= nx && nx < H && 0 <= ny && ny < W){
                            remapped[nx][ny] = '#';
                        }
                    }
                }
            }
        }
    }

    for(int x = 0; x < H; ++x){
        for(int y = 0; y < W; ++y){
            if(remapped[x][y] != field[x][y]){
                flg = false;
                break;
            }
        }
    }

    if(flg){
        cout << "possible" << endl;
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                cout << mapped[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "impossible" << endl;
    }

    return 0;
}