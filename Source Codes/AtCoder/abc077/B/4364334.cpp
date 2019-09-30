#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int N;
    long long ans;
    cin >> N;
    for(int i = 0; i <= N; i++){
        if(i * i <= N) ans = i*i;
        else break;
    }
    cout << ans <<endl;
}