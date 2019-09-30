#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;

//??????????Global??????
//????????????????
//step?????src?????????
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
/**
 *?????????????
 *Global??????
 */

    cin >> R >> C;
    cin >> sx >> sy;
    sx -= 1;
    sy -= 1;

    cin >> gx >> gy;
    gx -= 1;
    gy -= 1;

    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin >> c[i][j];
            visited[i][j] = false; 
        }
    }
    visited[0][0] = true;
    src[sx][sy] = 0;
}

int main(){
    //?????????
    int xNext, yNext;


    //?????????????
    init();

    //???????queue?push???
    //queue?x?y???????
    xq.push(sx);
    yq.push(sy);

    //DFS????
    do{

        int xi = xq.front();
        int yi = yq.front();
        xq.pop();
        yq.pop();

        //dx,dy??????????????
        //'.'????queue??????        
        for(int i = 0; i < 4; ++i){
            
            xNext = xi + dx[i];
            yNext = yi + dy[i];

            if(c[xNext][yNext] == '.' && !visited[xNext][yNext]){
                xq.push(xNext);
                yq.push(yNext);
                visited[xNext][yNext] = true;
                src[xNext][yNext] = src[xi][yi] + 1;

                //Goal????
                if(xNext == gx && yNext == gy){
                    cout << src[xNext][yNext] << endl;
                    return 0;

                } 
            }
        }
    //x,y?queue?????????????
    }while(!xq.empty() || !yq.empty());

    return 0;
}