#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define REP(i, N) for(int i = 0; i < N ; i ++)

int mouitta[50][50];
int main(int argc, const char * argv[]) {
    int H ,W;
    cin >> H >> W;
    char masume[50][50];
    int kabe = 0;
    REP(i, H){
        REP(j,W){
            cin >> masume[i][j];
            if(masume[i][j] == '#') {kabe++;}
        }
    }
    queue <pair<int, int>> masumequeue;
    queue <int> tuuka;
    tuuka.push(1);
    int susumu[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int genzaichi[2] = {0, 0};
    mouitta[0][0] = 1;
    int goal = 0;
    while(goal == 0){
        REP(i , 4){
            if ((genzaichi[0] == 0 && susumu[i][0] == -1) || (genzaichi[1] == 0 && susumu[i][1] == -1) || (genzaichi[0] == H - 1 && susumu[i][0] == 1) || (genzaichi[1] == W - 1 && susumu[i][1] == 1)){
                continue;
            }
            else if(genzaichi[0] + susumu[i][0] == H - 1 && genzaichi[1] + susumu[i][1] == W - 1){
                cout << H * W - kabe - tuuka.front() - 1;
                goal = 1;
                break;
            }
            else if((masume[genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] == '.') && (mouitta[genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] == 0)){
                mouitta[genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] = 1;
                masumequeue.push(pair<int,int>(genzaichi[0] + susumu[i][0],genzaichi[1] + susumu[i][1]));
                tuuka.push(tuuka.front() + 1);
            }
        }
        if(goal == 1) break;
        if(masumequeue.empty() == true){cout << -1;break;}
        genzaichi[0] = masumequeue.front().first;
        genzaichi[1] = masumequeue.front().second;
        masumequeue.pop();
        tuuka.pop();
    }
}