#include <iostream>
#include <queue>
using namespace std;

int R, C;
int A[51][51];
int S[51][51];

queue< pair <int,int> > Q;

int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };

void bfs_visit(int y, int x){
    Q.push(make_pair(y, x));
    S[y][x] = 0;
    int v, w;
    while(!Q.empty()){
        v = Q.front().first;
        w = Q.front().second;
        Q.pop();
    
        for(int i = 0; i < 4; i++){
            int ny = v + dy[i];
            int nx = w + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || S[ny][nx] != -1 || A[ny][nx] == -1){
                continue;
            }
            Q.push(make_pair(ny, nx));
            S[ny][nx] = S[v][w] + 1;
        }
    }
}

int main(void){
    // Your code here!
    cin >> R >> C;
    
    int sy, sx, gy, gx;
    cin >> sy >> sx;
    cin >> gy >> gx;
    
    char tmp;
    for(int i = 0; i< R; i++){
        for(int j = 0; j < C; j++){
            cin >> tmp;
            S[i][j] = -1;
            if(tmp == '.'){
                A[i][j] = 1;
            } else{
                A[i][j] = -1;
            }
        }
    }
    
    bfs_visit(sy-1, sx-1);
    
    cout << S[gy-1][gx-1] << endl;
    
    return 0;
}