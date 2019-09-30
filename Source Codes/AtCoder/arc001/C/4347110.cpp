#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int A,B;
    cin >> A >> B;
    int c = abs(B -A);
    int d = c % 10;
    int p;
    if (d >= 8){
        p = c/10 + 11 - d; 
    }
    else{
        if (d == 4){
            p = c/10 + 6 - d;
        }
        else{
            p = c/10 + (c % 10) / 5 + ((c % 10) % 5);
        }
    }
    cout << p << endl;
}