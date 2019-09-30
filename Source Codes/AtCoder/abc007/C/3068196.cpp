#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int sx, sy, gx, gy;
char c[55][55];
bool visited[55][55];
int src[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<int> xq;
queue<int> yq;

void init(){
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> gx >> gy;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin >> c[i][j];
            visited[i][j] = false; 
        }
    }
    visited[0][0] = true;
    src[sx - 1][sy -1] = 0;
}

int main(){
    int xNext, yNext;


    //initialize
    init();

    xq.push(sx-1);
    yq.push(sy-1);
    do{

        int xi = xq.front();
        int yi = yq.front();
        xq.pop();
        yq.pop();
        
        for(int i = 0; i < 4; ++i){
            
            xNext = xi + dx[i];
            yNext = yi + dy[i];

            if(c[xNext][yNext] == '.' && !visited[xNext][yNext]){
                xq.push(xNext);
                yq.push(yNext);
                visited[xNext][yNext] = true;
                src[xNext][yNext] = src[xi][yi] + 1;
                if(xNext == gx-1 && yNext == gy-1){
                    cout << src[xNext][yNext] << endl;
                    return 0;

                } 
            }
        }
    }while(!xq.empty() || !yq.empty());

    return 0;
}