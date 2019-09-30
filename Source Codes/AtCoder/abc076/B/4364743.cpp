#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int N, K;
    int s = 1;
    cin >> N >> K;
    while(N > 0){
        if(s < K){
            s *= 2;
        }else{
            s += K;
        }
        N--;
    }
    cout << s << endl;
}