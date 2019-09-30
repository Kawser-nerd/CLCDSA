#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(c >= a && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;
}