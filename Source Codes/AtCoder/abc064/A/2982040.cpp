#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int d;
    d = a * 100 + b * 10 + c;
    if(d % 4 == 0) cout << "YES";
    else cout << "NO";
}