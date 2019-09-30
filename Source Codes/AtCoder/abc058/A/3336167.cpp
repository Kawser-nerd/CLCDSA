#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b-a == c-b) cout << "YES" << endl;
    else cout << "NO" << endl;
}