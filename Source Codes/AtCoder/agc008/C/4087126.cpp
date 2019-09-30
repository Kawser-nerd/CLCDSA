#include <iostream>

using namespace std;

int main(){
    long a1, a2, a3, a4, a5, a6, a7;
    long K = 0;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7;
    K +=  a2;
    K += (a1/2)*2;
    K += (a4/2)*2;
    K += (a5/2)*2;
    if(a1%2 == 1 && a4%2 == 1 && a5%2 == 1){
        K+=3;
        cout << K <<  endl;
    }else if(a1%2 == 1 && a4%2 == 1 && a5 != 0){
        K++;
        cout << K <<  endl;
    }else if(a4%2 == 1 && a5%2 == 1 && a1 != 0){
        K++;
        cout << K <<  endl;
    }else if(a5%2 == 1 && a1%2 == 1 && a4 != 0){
        K++;
        cout << K <<  endl;
    }
    else{
        cout << K <<  endl;
    }
}