#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N == 3){
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        return 0;
    }
    if(N == 4){
        cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
        return 0;
    }
    int a[8] = {2, 3, 4, 6, 8, 9, 10, 12};
    int n = N/8;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            cout << a[j] + 12*i;
            if(N%8 != 0 || i != n-1 || j != 7) cout << ' ';
        }
    }
    if(N%8 == 0){
        cout << endl;
    }else if(N%8 == 1){
        cout << 6+12*n << endl;
    }else if(N%8 == 2){
        cout << 2+12*n << ' ' << 4+12*n << endl;
    }else if(N%8 == 3){
        cout << 2+12*n << ' ' << 4+12*n << ' ' << 6+12*n << endl;
    }else if(N%8 == 4){
        cout << 2+12*n << ' ' << 4+12*n << ' ' << 6+12*n << ' ' << 12+12*n << endl;
    }else if(N%8 == 5){
        cout << 3+12*n << ' ' << 8+12*n << ' ' << 9+12*n << ' ' << 10+12*n << ' ' << 12+12*n << endl;
    }else if(N%8 == 6){
        cout << 3+12*n << ' ' << 8+12*n << ' ' << 9+12*n << ' ' << 10+12*n << ' ' << 12+12*n << ' ' << 6+12*n << endl;
    }else if(N%8 == 7){
        cout << 3+12*n << ' ' << 8+12*n << ' ' << 9+12*n << ' ' << 10+12*n << ' ' << 12+12*n << ' ' << 2+12*n << ' ' << 4+12*n << endl;
    }
}