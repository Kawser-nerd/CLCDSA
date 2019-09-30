#include <iostream>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char r[500][500];
    char b[500][500];
    int M = min(H, W);
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(min(min(h-0, H-h-1),min(w-0, W-w-1))%2 == 0){
                if(h+1 == w && 2*h < M-1){
                    r[h][w] = '.';
                    b[h][w] = '#';
                }else{
                    r[h][w] = '#';
                    b[h][w] = '.';
                }
            }
            else {
                if(h+1 == w && 2*h < M-1){
                    r[h][w] = '#';
                    b[h][w] = '.';                    
                }else{
                    r[h][w] = '.';
                    b[h][w] = '#';
                }
            }
            //cout << r[h][w];
        }
    //cout << endl;
    }
    
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            char a;
            cin >> a;
            if(a == '#'){
                r[h][w] = '#';
                b[h][w] = '#';
            }
        }
    }
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cout << r[h][w];
        }
        cout << endl;
    }
    cout << endl;
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cout << b[h][w];
        }
        cout << endl;
    }
    
}