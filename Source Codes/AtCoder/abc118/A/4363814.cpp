#include<iostream>

using namespace std;
int main(void){
    int a,b;
    cin >> a;
    cin >> b;
    if ((b % a) == 0) {
        cout << (a + b) << endl;
    } else {
        cout << (b - a) << endl;
    }
    return 0;
}