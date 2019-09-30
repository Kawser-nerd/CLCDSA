#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    ll min, max;
    int flag = 0;
    for(int i = 0; i < N; ++i){
        min = C * i - D * (N - i - 1);
        max = D * i - C * (N - i - 1);
        if(min <= B - A && B - A <= max){
            flag = 1;
            break;   
        }
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}