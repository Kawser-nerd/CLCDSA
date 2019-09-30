#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    char stage[N][M+1];
    char stage2[N][M];
    char stage3[N][M];
    for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j){
        cin >> stage[i][j];
    }
    
    for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j){
        if(stage[i][j] == '#'){
            stage2[i][j] = '#';
        }
    }

    for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j){
        if(stage[i][j] == '.'){
            for(int p = -1; p <= 1; ++p)
            for(int q = -1; q <= 1; ++q){
                if(i + p < N && i + p >= 0 && j + q >= 0 && j + q < M){
                    stage2[i+p][j+q] = '.';
                }
            }
        }
    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(stage2[i][j] == '.'){
                stage3[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j){
        if(stage2[i][j] == '#'){
            for(int p = -1; p <= 1; ++p)
            for(int q = -1; q <= 1; ++q){
                if(i + p < N && i + p >= 0 && j + q >= 0 && j + q < M){
                    stage3[i+p][j+q] = '#';
                }
            }
        }
    }
    
    int flag = 0;

    for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j){
        if(stage[i][j] != stage3[i][j]){
            flag = 1;
            break;
        }
    }

    if(flag) cout << "impossible" << endl;
    else{
        cout << "possible" << endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                cout << stage2[i][j];
            }
            cout << endl;
        }   
    }
    return 0;
}