#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;

char A[15][15];
bool visited[15][15];
bool checked[15][15];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<int> xq;
queue<int> yq;

void init(){
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> A[i][j];
            visited[i][j] = false;
        }
    }
}

void islandcheck(){
    for(int i = 0; i < 10; ++i){
        for(int j = 0 ; j < 10; ++j){
            visited[i][j] = false;
            if(A[i][j] == 'o'){
                checked[i][j] = true;
            }else{
                checked[i][j] = false;
            }
        }
    }
}

void visitcheck(){
    for(int i = 0; i < 10; ++i){
        for(int j = 0 ; j < 10; ++j){
            visited[i][j] = false;
        }
    }
}

int main(){
    //?????????
    int xNext, yNext;
    int sum;
    //?????????????
    init();


    for(int sx = 0; sx < 10; ++sx){
        for (int sy = 0; sy < 10; ++sy){

            islandcheck();
            checked[sx][sy] = false;
            for(int gx = 0; gx < 10; ++gx){
                for(int gy = 0; gy < 10; ++gy){

                    visitcheck();
                    visited[sx][sy] = true;

                    if(A[gx][gy] == 'x'){
                        continue;
                    }
                    xq.push(sx);
                    yq.push(sy);
                
                    //BFS????
                    do{
                
                        int xi = xq.front();
                        int yi = yq.front();
                        xq.pop();
                        yq.pop();
                
                        for(int i = 0; i < 4; ++i){
                            
                            xNext = xi + dx[i];
                            yNext = yi + dy[i];
                
                            if(A[xNext][yNext] == 'o' && !visited[xNext][yNext]){
                                xq.push(xNext);
                                yq.push(yNext);
                                visited[xNext][yNext] = true;
                
                                if(xNext == gx && yNext == gy){
                                    checked[gx][gy] = false;
                                } 
                            }
                        }
                    //x,y?queue?????????????
                    }while(!xq.empty() || !yq.empty());
                }
            }
            sum = 0;
            for(int i = 0; i < 10; ++i){
                for(int j = 0; j < 10; ++j){
                    sum += checked[i][j];
                }
            } 
            if( !sum ){
                cout << "YES" << endl;
            return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}