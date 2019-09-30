#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(c-a) <= d) cout << "Yes" << endl;
    else if (abs(a-b) <= d && abs(b-c) <= d) cout << "Yes" << endl;
    else cout << "No" << endl;
}