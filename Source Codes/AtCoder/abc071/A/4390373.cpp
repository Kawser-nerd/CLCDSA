#include <iostream>

using namespace std;

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(abs(x-a) > abs(x-b)){
        cout << 'B' << endl;
    }else{
        cout << 'A' << endl;
    }
}