#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b == c) cout << "Yes" << endl;
    else if (a+c == b) cout << "Yes" << endl;
    else if (b+c == a) cout << "Yes" << endl;
    else cout <<"No" << endl;
}