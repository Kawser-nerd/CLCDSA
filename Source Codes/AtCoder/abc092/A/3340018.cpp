#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d, train, bus;
    cin >> a >> b >> c >> d;
    if(a>b) train = b;
    else train = a;
    if(c>d) bus = d;
    else bus = c;
    cout << train + bus << endl;
}