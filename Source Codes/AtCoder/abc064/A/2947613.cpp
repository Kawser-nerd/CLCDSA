#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {

    int r, g, b;
    int N;
    cin >> r >> g >> b;

    N = 100*r + 10*g + 1*b;

    if(N%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}