#include<iostream>

using namespace std;

int main(){
    int N, M, num, time, vol = 0;
    cin >>N;
    int ps[N];
    for(int i = 0; i < N; i++){
        cin >>ps[i];
    }
    cin >>M;
    class drinks{
    public:
        int p,t;
    };
    drinks ds[M];
    for(int i = 0; i < M; i++){
        cin >>num >>time;
        vol = 0;
        for(int j = 0; j < N; j++){
            if(j != num - 1){
                vol += ps[j];
            }else{
                vol += time;
            }
        }
        cout << vol << endl;
    }



}