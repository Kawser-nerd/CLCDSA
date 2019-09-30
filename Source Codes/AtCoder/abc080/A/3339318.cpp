#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    if(n*a < b) cout << n*a << endl;
    else cout << b << endl;
}