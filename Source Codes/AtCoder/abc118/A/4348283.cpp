#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int a,b;
    int p;
    cin >> a >> b;
    if (b % a == 0){
        p = a + b;
    }
    else{
        p = b - a; 
    }
    cout << p << endl; 
}