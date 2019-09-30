#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;
    if(abs(x-y) < 2){
        cout << "Brown" << endl;
    }else{
        cout << "Alice" << endl;
    }
    return 0;
}