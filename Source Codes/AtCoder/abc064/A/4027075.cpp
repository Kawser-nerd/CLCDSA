#include <iostream>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((10*g + b ) % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}