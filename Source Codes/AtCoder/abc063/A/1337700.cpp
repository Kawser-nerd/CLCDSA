#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a+b < 10){
        cout << a + b << endl;
    }
    else{
        cout << "error" << endl;
    }
    return 0;
}