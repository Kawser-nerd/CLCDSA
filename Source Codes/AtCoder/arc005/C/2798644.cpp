#include <iostream>
#include <cstdio>
#include <queue>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;

int mouitta[3][500][500];

int main(int argc, const char * argv[]) {
    int H, W;
    cin >> H >> W;
    int genzaichi[2];
    queue <pair <int, int>> nextqueue;
    queue <int> kowasitakaisuu;
    int nankaikowasita = 0;
    char town[500][500];
    REP(i ,H){
        REP(j, W){
            cin >> town[i][j];
            if(town[i][j] == 's'){
                genzaichi[0] = i;
                genzaichi[1] = j;
            }
        }
    }
    int owari = 0;
    int susumu[4][2] = {{-1, 0},{1,0 }, {0,-1},{0,1}};
    while(1){
        REP(i,4){
            if((genzaichi[0] == 0 && susumu[i][0] == -1) || (genzaichi[1] == 0 && susumu[i][1] == -1) || (genzaichi[0] == H - 1 && susumu[i][0] == 1) || (genzaichi[1] == W - 1 && susumu[i][1] == 1)){
                continue;
            }else if(mouitta[nankaikowasita][genzaichi[0] + susumu[i][0]][genzaichi[1]+susumu[i][1]] == 1){
                continue;
            }else if(town[genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] == 'g'){
                owari = 1;
                printf("YES\n");
                break;
            }else  if(town[genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] == '#'){
                if(nankaikowasita == 2){
                    continue;
                }else{
                    kowasitakaisuu.push(nankaikowasita + 1);
                    nextqueue.push(pair<int, int>(genzaichi[0] + susumu[i][0],genzaichi[1] + susumu[i][1]));
                    mouitta[nankaikowasita + 1][genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] = 1;
                }
            }else{
                kowasitakaisuu.push(nankaikowasita);
                nextqueue.push(pair<int, int>(genzaichi[0] + susumu[i][0],genzaichi[1] + susumu[i][1]));
                mouitta[nankaikowasita][genzaichi[0] + susumu[i][0]][genzaichi[1] + susumu[i][1]] = 1;
            }
        }
        if(owari == 1){
            break;
        }
        if(nextqueue.empty() == true){
            printf("NO\n");
            break;
        }        nankaikowasita = kowasitakaisuu.front();
        genzaichi[0] = nextqueue.front().first;
        genzaichi[1] = nextqueue.front().second;
        kowasitakaisuu.pop();
        nextqueue.pop();
    }
}