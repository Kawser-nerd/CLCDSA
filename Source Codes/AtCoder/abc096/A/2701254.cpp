#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    short a, b;
    cin >> a >> b;

    int counter = 0;
    if(a <= b){
        counter = a;
    }
    else{
        counter = a - 1;
    }

    cout << counter << "\n";

    return 0;
}