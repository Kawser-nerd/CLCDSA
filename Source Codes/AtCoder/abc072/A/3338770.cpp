#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int x, t;
    cin >> x >> t;
    if((x-t) > 0) cout << x-t << endl;
    else cout << 0 << endl;
}