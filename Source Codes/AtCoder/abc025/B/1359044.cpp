#include <iostream>
using namespace std;

int main(){
    int N, A, B, base = 0;
    cin >> N >> A >> B;
    string s;
    int d;
    for(int i = 0; i < N; ++i){
        cin >> s >> d;
        if(d < A){
            d = A;
        }else if(d > B){
            d = B;
        }
        if(s == "East"){
            base -= d;
        }else{
            base += d;
        }
    }

    if(base > 0){
        cout << "West " << base << endl;
    }else if(base == 0){
        cout << 0 << endl;
    }else{
        cout << "East " << -base<< endl;
    }

    return 0;
}