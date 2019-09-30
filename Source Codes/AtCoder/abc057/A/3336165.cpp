#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a+b < 24) cout << a+b << endl;
    else cout << a+b-24 << endl;
}