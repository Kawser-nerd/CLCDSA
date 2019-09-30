#include<iostream>
#include <string>
using namespace std;

int main(){
    int a, d;
    cin >> a >> d;
    if((a+1)*d > (d+1)*a){
        cout << (a+1) * d << endl;
    }
    else if((d+1)*a > (a+1)*d){
        cout << (d+1) * a << endl;
    }
    else cout << (a+1) * d << endl;
    return 0;
}