#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;

#define ll long long

int H,W;
char s[51][51];
char ans[51][51];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int main(){
    int H, W;
    int tmp;
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == '#'){
                ans[i][j] = '#';
                cout << ans[i][j];
            }else{
                int tmp = 0;
                for(int k = 0; k < 8; k++){
                    int ni, nj;
                    ni = i + dx[k];
                    nj = j + dy[k];
                    if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                        if(s[ni][nj] == '#') tmp++;
                    }
                }
                cout << tmp; 
            }
        }
        cout << endl;
    }
}