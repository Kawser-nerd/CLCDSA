//
// Created by Tetsuya Shiota on 2019-04-11.
//

#include<iostream>

using namespace std;

int main(){
    int N, Y;
    cin >> N >> Y;
    for(int i = 0; i<=N; i++){
        for(int j = 0; j+i<=N; j++){
            int now = 0, k = (N-i-j);
            now += i*10000;
            now += j*5000;
            now += k * 1000;
            if(Y == now){
                cout << i <<' '<<j<<' '<<k<<endl;
                return 0;
            }

        }
    }
    cout << "-1 -1 -1"<<endl;

}